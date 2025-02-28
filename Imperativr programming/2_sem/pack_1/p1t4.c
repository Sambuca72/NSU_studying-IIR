#include <stdio.h>
#include <stdlib.h>

int **c;

void triangle(int M, int max_n) {
    for (int n = 0; n <= max_n; n++) {
        c[n][0] = 1;
        c[n][n] = 1;
        for (int k = 1; k < n; k++) {
            c[n][k] = (c[n - 1][k - 1] + c[n - 1][k]) % M;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int M, T;
    scanf("%d %d", &M, &T);

    int max_n = 2000; // Максимальное значение N
    c = (int **)malloc((max_n + 1) * sizeof(int *));
    for (int i = 0; i <= max_n; i++) {
        c[i] = (int *)malloc((max_n + 1) * sizeof(int));
    }

    triangle(M, max_n);

    for (int i = 0; i < T; i++) {
        int n, k;
        scanf("%d %d", &n, &k);

        if (k < 0 || k > n) {
            printf("0\n");
        } else {
            printf("%d\n", c[n][k]);
        }
    }

    // Освобождаем память
    for (int i = 0; i <= max_n; i++) {
        free(c[i]);
    }
    free(c);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

// O(N^2+T)