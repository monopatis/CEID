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

__global__ void multiplication(double *d_out, double *d_in, int c, int r){

        int idx = blockIdx.x * blockDim.x + threadIdx.x;
        int l;
        double myP = 0;
        if(idx <= c * r ) {
                for(l = 0; l < r; l++) {
                        myP += d_in[idx/c + l * c] * d_in[idx % c + c * l];
                }
                d_out[idx] = myP;
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
        for (int i = 0; i < nr_rows_A * nr_cols_A; i++) {
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
        dim3 dimGrid(nr_rows_C, nr_cols_C, 1);
        cudaEventCreate( &start);  cudaCheckError();
        cudaEventCreate( &stop);  cudaCheckError();

        float totalTime[loops];
        int blockN = (nr_cols_A * nr_cols_A) / 1024 + 1;
        // Multiply A' and A on GPU
        for (int k = 0; k < loops; k++) {

                cudaEventRecord(start);  cudaCheckError();
                // Do the actual multiplication
                multiplication<<<blockN,1024>>>(d_C, d_A, nr_cols_A, nr_rows_A);
                // multiply<<<dimGrid, 1>>>( d_A, nr_rows_A, nr_cols_A, d_C );
                cudaThreadSynchronize(); cudaCheckError();
                cudaEventRecord(stop); cudaCheckError();

                // Copy (and print) the result on host memory
                cudaMemcpy(h_C, d_C, nr_rows_C * nr_cols_C * sizeof(double), cudaMemcpyDeviceToHost);
                cudaCheckError();
                cudaEventSynchronize(stop); cudaCheckError();
                float milliseconds = 0;
                cudaEventElapsedTime( &milliseconds, start, stop);
                cudaCheckError();
                cout << milliseconds <<endl;
                // cout << "\% ex2, Dimensions :" << nr_rows_A<< "x" << nr_cols_C << " , Time (msec): " << milliseconds << endl;
        }
        cout << endl;

        float mo = 0.0;
        for(int k = 0; k < loops; k++) {
                mo += totalTime[k];
        }
        mo /= (loops);
        cout << endl << "average time = " << mo << endl;

        cudaEventDestroy(start); cudaCheckError();
        cudaEventDestroy(stop); cudaCheckError();

        //Free GPU memory
        cudaFree(d_A); cudaCheckError();
        cudaFree(d_C); cudaCheckError();

        if (print) {
                cout << "C = [" << endl;
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
