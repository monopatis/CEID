// Low level matrix multiplication on GPU using CUDA with CURAND and CUBLAS
// C(M,M) = A'(M,N) * A(N,M)
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cublas_v2.h>
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

double * h_A, * h_C;

// Fill  random numbers on GPU
double fill_rand() {
        double s = 0, d = 0;
        //Gives a number between -20 and +20;
        s = rand() % 40 - 20;
        //Reduces this number
        d = s / 137;
        return d;
}

// Multiply the arrays A' and A on GPU and save the result in C
// C(k,k) = A'(k,m) * A(m,k)

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
        if (argc < 5) {
                cout << "Usage: "<< argv[0] << " Rows Cols Loops Print" << endl;
                return 1;
        }
        unsigned int nr_rows_A, nr_cols_A, nr_rows_C, nr_cols_C;
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
                cout << "]" << endl;
        }

        // Allocate 2 arrays on GPU
        double * d_A, * d_C;
        cudaMalloc( &d_A, nr_rows_A * nr_cols_A * sizeof(double));  cudaCheckError();
        cudaMalloc( &d_C, nr_rows_C * nr_cols_C * sizeof(double));  cudaCheckError();

        // Transfer the array to GPU
        cudaMemcpy(d_A, h_A, nr_rows_A * nr_cols_A  * sizeof(double), cudaMemcpyHostToDevice);
        cudaCheckError();
        cudaEventCreate( &start);  cudaCheckError();
        cudaEventCreate( &stop);  cudaCheckError();
        float totalTime[loops + 1];

        for (unsigned short k = 0; k < loops; k++) {
                const double alf = 1;
                const double bet = 0;
                const double * alpha = &alf;
                const double * beta = &bet;
                // Create a handle for CUBLAS
                cublasHandle_t handle;  cudaCheckError();
                cublasCreate( &handle); cudaCheckError();
                cudaEventRecord(start); cudaCheckError();

                // Do the actual multiplication
                cublasDgemm(handle, CUBLAS_OP_T, CUBLAS_OP_N, nr_cols_A, nr_cols_A, nr_rows_A,
                            alpha, d_A, nr_rows_A, d_A, nr_rows_A, beta, d_C, nr_cols_A);
                cudaCheckError();

                cudaEventRecord(stop); cudaCheckError();
                // Destroy the handle
                cublasDestroy(handle); cudaCheckError();
                // Copy the result on host memory
                cudaMemcpy(h_C, d_C, nr_rows_C * nr_cols_C * sizeof(double), cudaMemcpyDeviceToHost); cudaCheckError();
                cudaEventSynchronize(stop); cudaCheckError();
                float milliseconds = 0;
                cudaEventElapsedTime( &milliseconds, start, stop); cudaCheckError();
                cout << milliseconds << endl;
                totalTime[k] = milliseconds;
                // cout << "ex1, Dimensions :" << nr_rows_A<< "x" << nr_cols_C << " , Time (msec) : " << milliseconds << endl;
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
                cout << "C =" << endl;
                print_matrix(h_C, nr_rows_C, nr_cols_C);
        }

        // Free CPU memory
        free(h_A);
        free(h_C);

        return 0;
}
