// Multiply the arrays A' and A on GPU and save the result in C
// C(M,M) = A'(M,N) * A(N,M)
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include <stdio.h>
#include <sys/time.h>
using namespace std;

#define cudaCheckError() {                               \
                cudaError_t e = cudaGetLastError();                    \
                if (e != cudaSuccess) {                                \
                        printf("CUDA error %s:%d: %s\n", __FILE__, __LINE__, \
                               cudaGetErrorString(e));                      \
                        exit(1);                                             \
                }                                                      \
}

#define TILE_WIDTH 8
//επιστρέφει τον μεγαλύτερο μεταξύ δύο αριθμών
#define imax(a,b) (a>b ? a : b)

double *h_A, *h_C;

// Fill  random numbers on GPU
double fill_rand() {
        double s = 0, d = 0;
        //Gives a number between -20 and +20;
        s = rand() % 40 - 20;
        //Reduces this number
        d = s / 137;
        return d;
}

//Kernel για πίνακες που δεν είναι τετραγωνικοί
/*__global__ void multiplyNdiffM( double *A, int N, int M, double *C ) {

        unsigned int row = blockIdx.y * blockDim.y + threadIdx.y;
        unsigned int col = blockIdx.x * blockDim.x + threadIdx.x;
        double Cvalue = 0.0;
        for (unsigned int e = 0; e < N; ++e)
                Cvalue += A[row * N + e] * A[col * N + e];
        C[col * M + row] = Cvalue;

   }*/

__global__ void multiplication(double *d_out, double *d_in, int c, int r){

        int idx = blockIdx.x * blockDim.x + threadIdx.x;
        int l;
        double myP = 0;
        if(idx <= c * r ) {
                for(l = 0; l < r; l++) {

                        myP += d_in[idx/c * l + c] * d_in[idx % c * c + l];

                }
                d_out[idx] = myP;
        }


}
//Kernel για τετραγωνικούς πίνακες
//Δυστυχώς δεν καταφέραμε να τον κανουμε να δουλέψει για όλους τους συνδιασμούς
//διαστάσεων. Για Ν=1 ή Μ=1 υπολογίζει σωστά τις τιμές
__global__ void multiply( double *A, int N, int M, double *C ) {
        // για να αποφύγουμε Shared Memory Bank Conflicts προσθέτουμε μία στήλη ακόμη
        __shared__ double ds_M[TILE_WIDTH][TILE_WIDTH+1];
        __shared__ double ds_N[TILE_WIDTH][TILE_WIDTH+1];
        int bx = blockIdx.x, by = blockIdx.y,
            tx = threadIdx.x, ty = threadIdx.y,
            Row = by * TILE_WIDTH + ty,
            Col = bx * TILE_WIDTH + tx;
        double Cvalue = 0.0;
        if (Row-8<Col) {
                for (int m = 0; m < (imax(N,M)-1)/TILE_WIDTH+1; ++m) {
                        if (Row < M && m*TILE_WIDTH+tx < N)
                                ds_M[ty][tx] = A[Row*N + m*TILE_WIDTH+tx];
                        else
                                ds_M[ty][tx] = 0.0;
                        if (Col < M && m*TILE_WIDTH+ty < N)
                                ds_N[ty][tx] = A[(m*TILE_WIDTH+ty)+(M*Col)];
                        else
                                ds_N[ty][tx] = 0.0;
                        __syncthreads();
                        // για TILE_WIDTH = 8 ξετύλιγμα βρόχου
                        Cvalue += ds_M[ty][0] * ds_N[0][tx]+
                                  ds_M[ty][1] * ds_N[1][tx]+
                                  ds_M[ty][2] * ds_N[2][tx]+
                                  ds_M[ty][3] * ds_N[3][tx]+
                                  ds_M[ty][4] * ds_N[4][tx]+
                                  ds_M[ty][5] * ds_N[5][tx]+
                                  ds_M[ty][6] * ds_N[6][tx]+
                                  ds_M[ty][7] * ds_N[7][tx];
                        __syncthreads();
                }
                if (Row < M && Col < M ) {
                        C[Col*M+Row] = Cvalue;
                        //ταυτόχρονα αποθηκεύουμε και το συμμετρικό του στοιχείο
                        if (Row < Col)
                                C[Row*M+Col] = Cvalue;
                }

        }
}

//Print matrix A(nr_rows_A, nr_cols_A) storage in column-major format
void print_matrix(const double * A, int nr_rows_A, int nr_cols_A) {
        for (int i = 0; i < nr_rows_A; ++i) {
                for (int j = 0; j < nr_cols_A; ++j) {
                        cout << std::setprecision(15) << A[j * nr_rows_A + i] << " ";
                }
                cout << " ; "<< endl;
        }
}

int main(int argc, char * * argv) {
        srand(time(0));
        cudaSetDevice(0); cudaCheckError();

        unsigned int nr_rows_A, nr_cols_A, nr_rows_C, nr_cols_C;
        if (argc < 5) {
                cout << "Usage: "<< argv[0] << " Rows Cols Loops Print" << endl;
                return 1;
        }
        if ((atoi(argv[1]) < 1) || (atoi(argv[2]) < 1)) {
                cout << "Only positive" << endl;
                return 1;
        }
        nr_rows_A = atoi(argv[1]);
        nr_cols_A = nr_rows_C = nr_cols_C = atoi(argv[2]);

        unsigned short loops = atoi(argv[3]);
        bool print = atoi(argv[4]);

        cudaEvent_t start, stop;

        // Allocate 2 arrays on CPU
        double * h_A = (double * ) malloc(nr_rows_A * nr_cols_A * sizeof(double));
        double * h_C = (double * ) malloc(nr_rows_C * nr_cols_C * sizeof(double));

        // here we fill the initial array with random double numbers
        for (unsigned int i = 0; i < nr_rows_A * nr_cols_A; i++) {
                h_A[i] = fill_rand();
        }

        if (print) {
                cout << "A = [" << endl;
                print_matrix(h_A, nr_rows_A, nr_cols_A);
                cout << "];" << endl;
        }

        // Allocate 2 arrays on GPU
        double *d_A, *d_C;
        cudaMalloc( &d_A, nr_rows_A * nr_cols_A * sizeof(double) ); cudaCheckError();
        cudaMalloc( &d_C, nr_rows_C * nr_cols_C * sizeof(double) ); cudaCheckError();
        // Transfer the array to GPU
        cudaMemcpy(d_A, h_A, nr_rows_A * nr_cols_A  * sizeof(double), cudaMemcpyHostToDevice);
        cudaCheckError();
        // Αρχικοποίηση του πίνακα h_C με μηδενικά
        for (int i = 0; i < nr_rows_C * nr_cols_C; i++) {
                h_C[i] = 0.0;
        }
        cudaMemcpy(d_C, h_C, nr_rows_C * nr_cols_C * sizeof(double), cudaMemcpyHostToDevice);
        cudaCheckError();

        // Κάθε block θα έχει διάσταση
        unsigned int BLOCK_SIZE_PER_DIM = TILE_WIDTH;
        // Στρογγυλοποίηση προς τα πάνω για το πλήθος των block σε κάθε διάσταση
        unsigned int numBlocks = (imax(nr_rows_A,nr_cols_A)  - 1) / BLOCK_SIZE_PER_DIM + 1;
        // Ορισμός διαστάσεων πλέγματος
        dim3 dimGrid(numBlocks, numBlocks, 1);
        // Ορισμός διαστάσεων block
        dim3 dimBlock(BLOCK_SIZE_PER_DIM, BLOCK_SIZE_PER_DIM, 1);
        // cout << "\%dimGrid(" << numBlocks<< "," << numBlocks << ", 1) , dimBlock(";
        // cout << BLOCK_SIZE_PER_DIM << "," << BLOCK_SIZE_PER_DIM << ", 1);" << endl;
        cudaEventCreate( &start); cudaCheckError();
        cudaEventCreate( &stop); cudaCheckError();

        float totalTime[loops];
        int blockN = (nr_cols_A * nr_cols_A) / 1024 + 1;
        // Multiply A' and A on GPU
        for (int k = 0; k < loops; k++) {
                cudaEventRecord(start); cudaCheckError();
                // Κλήση υπολογιστικού πυρήνα
                if (nr_rows_A==nr_cols_A) {
                        multiply<<<dimGrid, dimBlock>>>( d_A, nr_rows_A, nr_cols_A, d_C );
                }
                else {
                        dim3 dimGrid(nr_rows_C, nr_cols_C, 1);
                        multiplication<<<blockN,1024>>>(d_C, d_A, nr_cols_A, nr_rows_A);
                }
                cudaCheckError();
                cudaThreadSynchronize(); cudaCheckError();
                cudaEventRecord(stop); cudaCheckError();

                // Copy the result on host memory
                cudaMemcpy(h_C, d_C, nr_rows_C * nr_cols_C * sizeof(double), cudaMemcpyDeviceToHost);
                cudaCheckError();
                cudaEventSynchronize(stop); cudaCheckError();
                float milliseconds = 0;
                cudaEventElapsedTime( &milliseconds, start, stop); cudaCheckError();
                cout << milliseconds << endl;
                totalTime[k] = milliseconds;
                // cout << "\%ex3, Dimensions :" << nr_rows_A<< "x" << nr_cols_C << " , Time (msec) : " << milliseconds << endl;
        }

        cudaEventDestroy(start); cudaCheckError();
        cudaEventDestroy(stop); cudaCheckError();

        float mo = 0.0;
        for(int k = 0; k < loops; k++) {
                mo += totalTime[k];
        }
        mo /= (loops);
        cout << endl << "average time = " << mo << endl;

        //Free GPU memory
        cudaFree(d_A); cudaCheckError();
        cudaFree(d_C); cudaCheckError();

        if (print) {
                cout << endl << "C = [" << endl;
                print_matrix(h_C, nr_rows_C, nr_cols_C);
                cout << "];" << endl;
                //Για επαλήθευση σε MATLAB
                cout<< "B=A'*A; D=B-C;" << endl;
        }

        // Free CPU memory
        free(h_A);
        free(h_C);

        return 0;
}
