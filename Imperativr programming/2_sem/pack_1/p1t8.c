#include <stdio.h>
#include <stdlib.h>

#define MODULO 1000000007

// Функция для быстрого возведения в степень по модулю
int mod_pow(int base, int exp, int mod) {
    int res = 1;
    while (exp > 0) {
        if (exp % 2) res = (1LL * res * base) % mod;
        base = (1LL * base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Функция для нахождения обратного элемента по модулю P (P - простое)
int mod_inv(int a, int p) {
    return mod_pow(a, p - 2, p);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k, P;
    scanf("%d %d %d", &n, &k, &P);

    int a[k][n + 1];

    // Чтение системы уравнений
    for (int i = 0; i < k; i++)
        for (int j = 0; j <= n; j++)
            scanf("%d", &a[i][j]);

    int row = 0; // Текущая строка

    // Прямой ход метода Гаусса
    for (int col = 0; col < n && row < k; col++) {
        // Поиск ведущего элемента (наибольшего по модулю)
        int pivot = row;
        for (int i = row + 1; i < k; i++)
            if (abs(a[i][col]) > abs(a[pivot][col]))
                pivot = i;

        if (a[pivot][col] == 0) continue; // Свободная переменная

        // Меняем местами строки
        for (int j = 0; j <= n; j++) {
            int tmp = a[row][j];
            a[row][j] = a[pivot][j];
            a[pivot][j] = tmp;
        }

        // Нормируем ведущий элемент
        int inv = mod_inv(a[row][col], P);
        for (int j = col; j <= n; j++)
            a[row][j] = (1LL * a[row][j] * inv) % P;

        // Обнуление всех элементов ниже
        for (int i = row + 1; i < k; i++) {
            int factor = a[i][col];
            for (int j = col; j <= n; j++)
                a[i][j] = (a[i][j] - 1LL * factor * a[row][j] % P + P) % P;
        }
        row++;
    }

    // Проверка на несовместность
    for (int i = row; i < k; i++)
        if (a[i][n] != 0) {
            printf("0\n");
            return 0;
        }

    // Обратный ход метода Гаусса
    int free_variables = n - row;
    int solution[n];
    for (int i = 0; i < n; i++)
        solution[i] = -1;

    for (int i = row - 1; i >= 0; i--) {
        int col = -1;
        for (int j = 0; j < n; j++)
            if (a[i][j] != 0) {
                col = j;
                break;
            }
        if (col == -1) continue;

        solution[col] = a[i][n];
        for (int j = col + 1; j < n; j++)
            if (solution[j] != -1)
                solution[col] = (solution[col] - 1LL * a[i][j] * solution[j] % P + P) % P;
    }

    // Если есть свободные переменные
    if (free_variables > 0) {
        printf("%d\n", mod_pow(P, free_variables, MODULO));
    } else {
        // Вывод единственного решения
        for (int i = 0; i < n; i++)
            printf("%d\n", solution[i] == -1 ? 0 : solution[i]);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
