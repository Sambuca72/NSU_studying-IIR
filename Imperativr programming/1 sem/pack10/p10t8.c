#include <stdio.h>
#define MAX_N 2000

char relation[MAX_N][MAX_N + 1]; // Матрица смежности + 1 для \0
int N;

void reflexive_transitive_closure() {
    // Добавляем рефлексивность
    for (int i = 0; i < N; i++) {
        relation[i][i] = '1';
    }

    // Алгоритм Уоршалла для транзитивного замыкания
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (relation[i][k] == '1') {
                for (int j = 0; j < N; j++) {
                    if (relation[k][j] == '1') {
                        relation[i][j] = '1';
                    }
                }
            }
        }
    }
}

int main() {
    // Открываем файлы
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Считываем размерность множества
    scanf("%d", &N);

    // Считываем матрицу отношения
    for (int i = 0; i < N; i++) {
        scanf("%s", relation[i]);
    }

    // Вычисляем рефлексивно-транзитивное замыкание
    reflexive_transitive_closure();

    // Вывод результата
    for (int i = 0; i < N; i++) {
        printf("%s\n", relation[i]);
    }

    return 0;
    fclose(stdin);
    fclose(stdout);
}
