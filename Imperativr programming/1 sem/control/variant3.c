#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000


typedef struct {
    int rows;
    int cols;
    int **data;
    char operation;
} Matrix;

Matrix createMatrix(int rows, int cols, char operation) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.operation = operation;
    mat.data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; ++i) {
        mat.data[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; ++j) {
            mat.data[i][j] = 0;
        }
    }
    return mat;
}


void changeValue(Matrix *mat, int row, int col, int value) {
    if (row >= 0 && row < mat->rows && col >= 0 && col < mat->cols) {
        if (mat->operation == '-') {
            value = -value;
        }
        mat->data[row][col] = value;
    }
}


void printMatrix(Matrix *mat){
    for(int i =0;i<mat->rows;i++){
        for(int j =0;j<mat->cols;j++){
            printf("%d", mat->data[i][j]);
            
        }
        printf("\n");
    }
}




Matrix addMatrices(Matrix *mat1, Matrix *mat2) {
    int maxRows = mat1->rows > mat2->rows ? mat1->rows : mat2->rows;
    int maxCols = mat1->cols > mat2->cols ? mat1->cols : mat2->cols;

    Matrix result = createMatrix(maxRows, maxCols, '+');

    for (int i = 0; i < maxRows; ++i) {
        for (int j = 0; j < maxCols; ++j) {
            int val1 = (i < mat1->rows && j < mat1->cols) ? mat1->data[i][j] : 0;
            int val2 = (i < mat2->rows && j < mat2->cols) ? mat2->data[i][j] : 0;



            result.data[i][j] = val1 + val2;
        }
    }

    return result;
}


void freeMatrix(Matrix *mat) {
    for (int i = 0; i < mat->rows; ++i) {
        free(mat->data[i]);
    }
    free(mat->data);
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    Matrix matrices[MAX_SIZE];  
    int matCount = 0;
    char command[10];
    char operation = '+';
    

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "CREATE") == 0) {
            int rows, cols;
            char op = '+';
            if (scanf("%d %d", &rows, &cols) == 2) {
                
                if (scanf(" %c", &op) != 1 || (op != '+' && op != '-')) {
                    op = '+';
                }

                
                matrices[matCount++] = createMatrix(rows, cols, op);
            }
        } else if (strcmp(command, "CHANGE") == 0) {
            int row, col, value;
            if (scanf("%d %d %d", &row, &col, &value) == 3) {
                changeValue(&matrices[matCount - 1], row, col, value);
            }
        }
    }

    
    Matrix result = matrices[0];
    for (int i = 1; i < matCount; ++i) {
        Matrix temp = addMatrices(&result, &matrices[i]);
        freeMatrix(&result);
        result = temp;
    }

    
    printMatrix(&result);

    
    freeMatrix(&result);
    for (int i = 0; i < matCount; ++i) {
        freeMatrix(&matrices[i]);
    }
    return 0;
    fclose(stdin);
    fclose(stdout);

}
