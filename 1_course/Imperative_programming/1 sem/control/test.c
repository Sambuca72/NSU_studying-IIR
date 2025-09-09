#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MATRICES 100

// Структура для хранения матрицы
typedef struct {
    int rows;
    int cols;
    int **data;
    char operation; // Сохраняем операцию ('+' или '-')
} Matrix;

// Функция для создания матрицы
Matrix createMatrix(int rows, int cols, char operation) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.operation = operation;
    mat.data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; ++i) {
        mat.data[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; ++j) {
            mat.data[i][j] = 0; // Изначально все элементы равны 0
        }
    }
    return mat;
}

// Функция для изменения значения в ячейке матрицы
void changeValue(Matrix *mat, int row, int col, int value) {
    if (row >= 0 && row < mat->rows && col >= 0 && col < mat->cols) {
        mat->data[row][col] = value;
    }
}

// Функция для сложения двух матриц
Matrix addMatrices(Matrix *mat1, Matrix *mat2) {
    int maxRows = mat1->rows > mat2->rows ? mat1->rows : mat2->rows;
    int maxCols = mat1->cols > mat2->cols ? mat1->cols : mat2->cols;

    Matrix result = createMatrix(maxRows, maxCols, '+');

    for (int i = 0; i < maxRows; ++i) {
        for (int j = 0; j < maxCols; ++j) {
            int val1 = (i < mat1->rows && j < mat1->cols) ? mat1->data[i][j] : 0;
            int val2 = (i < mat2->rows && j < mat2->cols) ? mat2->data[i][j] : 0;

            // Учитываем знак матриц
            if (mat1->operation == '-') val1 = -val1;
            if (mat2->operation == '-') val2 = -val2;

            result.data[i][j] = val1 + val2;
        }
    }

    return result;
}

// Очистка памяти, выделенной под матрицу
void freeMatrix(Matrix *mat) {
    for (int i = 0; i < mat->rows; ++i) {
        free(mat->data[i]);
    }
    free(mat->data);
}

// Вывод матрицы
void printMatrix(Matrix *mat) {
    for (int i = 0; i < mat->rows; ++i) {
        for (int j = 0; j < mat->cols; ++j) {
            printf("%d", mat->data[i][j]);
            if (j < mat->cols - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char command[10];
    Matrix matrices[MAX_MATRICES];
    int matCount = 0;

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "CREATE") == 0) {
            int rows, cols;
            char op = '+';
            if (scanf("%d %d", &rows, &cols) == 2) {
                // Проверяем, указана ли операция
                if (scanf(" %c", &op) != 1 || (op != '+' && op != '-')) {
                    op = '+';
                }

                // Создаем матрицу
                matrices[matCount++] = createMatrix(rows, cols, op);
            }
        } else if (strcmp(command, "CHANGE") == 0) {
            int row, col, value;
            if (scanf("%d %d %d", &row, &col, &value) == 3) {
                changeValue(&matrices[matCount - 1], row, col, value);
            }
        }
    }

    // Складываем все матрицы
    Matrix result = matrices[0];
    for (int i = 1; i < matCount; ++i) {
        Matrix temp = addMatrices(&result, &matrices[i]);
        freeMatrix(&result);
        result = temp;
    }

    // Выводим итоговую матрицу
    printMatrix(&result);

    // Очистка памяти
    freeMatrix(&result);
    for (int i = 0; i < matCount; ++i) {
        freeMatrix(&matrices[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
