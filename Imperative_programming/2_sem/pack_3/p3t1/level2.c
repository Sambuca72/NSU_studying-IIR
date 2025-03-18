#include "myblas.h"

//====== уровень 2 ======
//вычислить вектор (alpha*A*X + beta*Y) длины m, и записать его в Y
//здесь A –- матрица размера m на n, X –- вектор длины n, а Y –- вектор длины m
void dgemv(int m, int n,
    double alpha , const double *A, const double *X,
    double beta , double *Y){
        for(int i = 0;i < m; i++){
            Y[i]*=beta;
        }

        for(int i = 0; i<n;i++){
            double sum = 0.0;
            for (int j = 0; j < n; j++){
                sum += A[i * n + j] *X[j];
            }
            Y[i] += alpha*sum;
        }
    }
    
    
    //вычислить матрицу (alpha*X*Yt + A) и записать её в A
    //здесь Yt –- это транспонированный вектор Y, то есть записанный как вектор-строка
    // A –- матрица размера m на n, X –- вектор длины m, а Y –- вектор длины n
void dger(int m, int n,
    double alpha , const double *X, const double *Y,
    double *A){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                A[i*n+j] += alpha*X[i]*Y[j];
            }
        }
    }