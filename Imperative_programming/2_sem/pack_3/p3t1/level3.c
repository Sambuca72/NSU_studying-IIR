#include "myblas.h"

//====== уровень 3 ======
//вычислить матрицу (alpha*A*B + beta*C) и записать её в C
//здесь A –- матрица размера m на k, B –- матрица размера k на n,
// C –- матрица размера m на n
void dgemm(int m, int n, int k,
    double alpha , const double *A, const double *B,
    double beta , double *C){

        for(int i = 0; i<m;i++){
            for(int j =0; j<n;j++){
                C[i*n+j]*=beta;
            }
        }

        for(int i = 0;i<m;i++){
            for(int j = 0; j<n;j++){
                for(int l=0; l<k;l++){
                    C[i*n+j]+=alpha*A[i*k+l]*B[l*n+j];
                }
            }
        }
        
    }