// #include "myblas.h"
// #include <stdio.h>
#include <stdlib.h>
#include <math.h>

// // Функция для сравнения двух double с учетом погрешности
// int double_equals(double a, double b) {
//     return fabs(a - b) < 1e-9;
// }

// // Функция для вывода вектора
// void print_vector(const char *name, int n, const double *v) {
//     printf("%s = [", name);
//     for (int i = 0; i < n; i++) {
//         printf("%.1f", v[i]);
//         if (i < n - 1) printf(", ");
//     }
//     printf("]\n");
// }

// // Функция для вывода матрицы
// void print_matrix(const char *name, int m, int n, const double *mat) {
//     printf("%s =\n", name);
//     for (int i = 0; i < m; i++) {
//         printf("[");
//         for (int j = 0; j < n; j++) {
//             printf("%.1f", mat[i * n + j]);
//             if (j < n - 1) printf(", ");
//         }
//         printf("]\n");
//     }
// }

// int main() {
//     printf("Starting BLAS tests...\n\n");

//     // Тест 1: dcopy
//     double X1[] = {1.0, 2.0, 3.0};
//     double Y1[3] = {0.0};
//     dcopy(3, X1, Y1);
//     printf("Test dcopy:\n");
//     print_vector("X", 3, X1);
//     print_vector("Y", 3, Y1);
//     int dcopy_ok = double_equals(Y1[0], 1.0) && double_equals(Y1[1], 2.0) && double_equals(Y1[2], 3.0);
//     printf("Result: %s\n\n", dcopy_ok ? "PASS" : "FAIL");

//     // Тест 2: dswap
//     double X2[] = {1.0, 2.0, 3.0};
//     double Y2[] = {4.0, 5.0, 6.0};
//     dswap(3, X2, Y2);
//     printf("Test dswap:\n");
//     print_vector("X", 3, X2);
//     print_vector("Y", 3, Y2);
//     int dswap_ok = double_equals(X2[0], 4.0) && double_equals(Y2[0], 1.0);
//     printf("Result: %s\n\n", dswap_ok ? "PASS" : "FAIL");

//     // Тест 3: dscal
//     double X3[] = {1.0, 2.0, 3.0};
//     dscal(3, 2.0, X3);
//     printf("Test dscal:\n");
//     print_vector("X", 3, X3);
//     int dscal_ok = double_equals(X3[0], 2.0) && double_equals(X3[1], 4.0) && double_equals(X3[2], 6.0);
//     printf("Result: %s\n\n", dscal_ok ? "PASS" : "FAIL");

//     // Тест 4: daxpy
//     double X4[] = {1.0, 2.0, 3.0};
//     double Y4[] = {4.0, 5.0, 6.0};
//     daxpy(3, 2.0, X4, Y4);
//     printf("Test daxpy:\n");
//     print_vector("X", 3, X4);
//     print_vector("Y", 3, Y4);
//     int daxpy_ok = double_equals(Y4[0], 6.0) && double_equals(Y4[1], 9.0) && double_equals(Y4[2], 12.0);
//     printf("Result: %s\n\n", daxpy_ok ? "PASS" : "FAIL");

//     // Тест 5: ddot
//     double X5[] = {1.0, 2.0, 3.0};
//     double Y5[] = {4.0, 5.0, 6.0};
//     double dot_result = ddot(3, X5, Y5);
//     printf("Test ddot:\n");
//     print_vector("X", 3, X5);
//     print_vector("Y", 3, Y5);
//     printf("Dot product = %.1f\n", dot_result);
//     int ddot_ok = double_equals(dot_result, 32.0); // 1*4 + 2*5 + 3*6 = 32
//     printf("Result: %s\n\n", ddot_ok ? "PASS" : "FAIL");

//     // Тест 6: dgemv
//     double A6[] = {1.0, 2.0, 3.0, 4.0}; // 2x2
//     double X6[] = {5.0, 6.0};
//     double Y6[] = {0.0, 0.0};
//     dgemv(2, 2, 2.0, A6, X6, 0.0, Y6); // Y = 2.0 * A * X
//     printf("Test dgemv:\n");
//     print_matrix("A", 2, 2, A6);
//     print_vector("X", 2, X6);
//     print_vector("Y", 2, Y6);
//     int dgemv_ok = double_equals(Y6[0], 34.0) && double_equals(Y6[1], 78.0); // [17, 24] * 2
//     printf("Result: %s\n\n", dgemv_ok ? "PASS" : "FAIL");

//     // Тест 7: dger
//     double X7[] = {1.0, 2.0};
//     double Y7[] = {3.0, 4.0};
//     double A7[] = {0.0, 0.0, 0.0, 0.0}; // 2x2
//     dger(2, 2, 2.0, X7, Y7, A7); // A += 2.0 * X * Y^T
//     printf("Test dger:\n");
//     print_vector("X", 2, X7);
//     print_vector("Y", 2, Y7);
//     print_matrix("A", 2, 2, A7);
//     int dger_ok = double_equals(A7[0], 6.0) && double_equals(A7[1], 8.0) &&
//                   double_equals(A7[2], 12.0) && double_equals(A7[3], 16.0);
//     printf("Result: %s\n\n", dger_ok ? "PASS" : "FAIL");

//     // Тест 8: dgemm
//     double A8[] = {1.0, 2.0, 3.0, 4.0}; // 2x2
//     double B8[] = {5.0, 6.0, 7.0, 8.0}; // 2x2
//     double C8[] = {0.0, 0.0, 0.0, 0.0}; // 2x2
//     dgemm(2, 2, 2, 2.0, A8, B8, 0.0, C8); // C = 2.0 * A * B
//     printf("Test dgemm:\n");
//     print_matrix("A", 2, 2, A8);
//     print_matrix("B", 2, 2, B8);
//     print_matrix("C", 2, 2, C8);
//     int dgemm_ok = double_equals(C8[0], 38.0) && double_equals(C8[1], 44.0) &&
//                    double_equals(C8[2], 86.0) && double_equals(C8[3], 100.0);
//     printf("Result: %s\n\n", dgemm_ok ? "PASS" : "FAIL");

//     return 0;
// }

#include<stdio.h>

// нкция для сравнения двух double с учетом погрешности
int double_equals(double a, double b) {
    return fabs(a - b) < 1e-9;
}

// Функция для вывода вектора
void print_vector(const char *name, int n, const double *v) {
    printf("%s = [", name);
    for (int i = 0; i < n; i++) {
        printf("%.1f", v[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

// Функция для вывода матрицы
void print_matrix(const char *name, int m, int n, const double *mat) {
    printf("%s =\n", name);
    for (int i = 0; i < m; i++) {
        printf("[");
        for (int j = 0; j < n; j++) {
            printf("%.1f", mat[i * n + j]);
            if (j < n - 1) printf(", ");
        }
        printf("]\n");
    }
}

//====== уровень 3 ======
//вычислить матрицу (alpha*A*B + beta*C) и записать её в C
//здесь A –- матрица размера m на k, B –- матрица размера k на n,
// C –- матрица размера m на n
void dgemm(int m, int n, int k,
    double alpha , const double *A, const double *B,
    double beta , double *C){

        for(int i = 0;i<m;i++){
            for(int j = 0; j<n;j++){
                for(int l=0; l<k;l++){
                    if (beta == 0.0){
                        C[i*n+j]+= alpha * A[i*k+l] * B[l*n+j];    
                    }else {
                        C[i*n+j]= C[i*n+j]*beta + alpha * A[i*k+l] * B[l*n+j];
                    }                   
                }
            }
        }
        
    }

int main(){
    double A8[] = {1.0, 2.0, 3.0, 4.0}; // 2x2
    double B8[] = {5.0, 6.0, 7.0, 8.0}; // 2x2
    double C8[] = {0.0, 0.0, 0.0, 0.0}; // 2x2
    dgemm(2, 2, 2, 2.0, A8, B8, 0.0, C8); // C = 2.0 * A * B
    printf("Test dgemm:\n");
    print_matrix("A", 2, 2, A8);
    print_matrix("B", 2, 2, B8);
    print_matrix("C", 2, 2, C8);
    int dgemm_ok = double_equals(C8[0], 38.0) && double_equals(C8[1], 44.0) &&
                   double_equals(C8[2], 86.0) && double_equals(C8[3], 100.0);
    printf("Result: %s\n\n", dgemm_ok ? "PASS" : "FAIL");  
}