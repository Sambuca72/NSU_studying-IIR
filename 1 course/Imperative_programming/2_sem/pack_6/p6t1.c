#include <stdio.h>
#include <stdlib.h>


//зачем нужна рекурсия
#define MAX 12
//при м <= 12 рекурсивная глубина безопасна
//если итеративно, то потребуется всякой фигней заниматься, больше писать, но можно самому ограничиваь стэк 


int M, N;
char **field_input;
int **field;
int *col;
int *usedcol;
int *diag1, *diag2;
int sol;

void ferzi_epta(int row, int **field) {
    if (sol) return;
    if (row == M) {
        sol = 1;
        return;
    }
    
    for (int j = 0; j < N; j++) {
        if (field[row][j] && !usedcol[j] && !diag1[row + j] && !diag2[row - j + N]) {
            col[row] = j;
            usedcol[j] = 1;
            diag1[row + j] = 1;
            diag2[row - j + N] = 1;
            
            ferzi_epta(row + 1, field);
            
            if (sol) return;
            
            usedcol[j] = 0;
            diag1[row + j] = 0;
            diag2[row - j + N] = 0;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d %d", &M, &N);
    
    if (M > N) {
        printf("NO\n");
        return 0;
    }
    
    field_input = (char **)malloc(M * sizeof(char *));
    field = (int **)malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) {
        field_input[i] = (char *)malloc(N + 1);
        field[i] = (int *)malloc(N * sizeof(int));
        scanf("%s", field_input[i]);
        for (int j = 0; j < N; j++) {
            field[i][j] = (field_input[i][j] == '?') ? 1 : 0;
        }
    }
    
    for (int i = 0; i < M; i++) {
        int has_allowed = 0;
        for (int j = 0; j < N; j++) {
            if (field[i][j]) {
                has_allowed = 1;
                break;
            }
        }
        if (!has_allowed) {
            printf("NO\n");
            for (int k = 0; k < M; k++) {
                free(field_input[k]);
                free(field[k]);
            }
            free(field_input);
            free(field);
            return 0;
        }
    }
    
    col = (int *)malloc(M * sizeof(int));
    usedcol = (int *)calloc(N, sizeof(int));
    diag1 = (int *)calloc(M + N, sizeof(int));
    diag2 = (int *)calloc(M + N, sizeof(int));
    sol = 0;
    
    ferzi_epta(0, field);
    
    if (sol) {
        printf("YES\n");
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (field_input[i][j] == '?' && col[i] == j) {
                    printf("X");
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }
    } else {
        printf("NO\n");
    }
    
    for (int i = 0; i < M; i++) {
        free(field_input[i]);
        free(field[i]);
    }
    free(field_input);
    free(field);
    free(col);
    free(usedcol);
    free(diag1);
    free(diag2);
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}