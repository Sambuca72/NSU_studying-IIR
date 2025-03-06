#include <stdio.h>
#include <stdlib.h>

void gaussian_elimination(int N, double **matrix, double *x) {
    // Прямой ход метода Гаусса
    for (int i = 0; i < N; i++) {
        // Поиск максимального элемента в текущем столбце
        int max_row = i;
        for (int k = i + 1; k < N; k++) {
            if (abs(matrix[k][i]) > abs(matrix[max_row][i])) {
                max_row = k;
            }
        }

        // Перестановка строк
        double *temp = matrix[i];
        matrix[i] = matrix[max_row];
        matrix[max_row] = temp;

        // Нормализация текущей строки
        for (int k = i + 1; k <= N; k++) {
            matrix[i][k] /= matrix[i][i];
        }
        matrix[i][i] = 1.0;

        // Обнуление элементов ниже текущего
        for (int k = i + 1; k < N; k++) {
            double factor = matrix[k][i];
            for (int j = i; j <= N; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    // Обратный ход метода Гаусса
    for (int i = N - 1; i >= 0; i--) {
        x[i] = matrix[i][N];
        for (int j = i + 1; j < N; j++) {
            x[i] -= matrix[i][j] * x[j];
        }
    }
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int N;
    scanf("%d", &N);

    double **matrix = (double **)malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++) {
        matrix[i] = (double *)malloc((N + 1) * sizeof(double));
    }
    double *x = (double *)malloc(N * sizeof(double));


    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Решение системы
    gaussian_elimination(N, matrix, x);

    for (int i = 0; i < N; i++) {
        printf("%.10lf\n", x[i]);
    }


    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(x);

    return 0;
    fclose(stdin);
    fclose(stdout);
}//итерационный алгоритм