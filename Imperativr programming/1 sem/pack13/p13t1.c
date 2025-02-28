#include <stdio.h>

// Функция для вычисления e^X с помощью ряда Тейлора
double compute_exp(double x) {
    if (x < 0) {
        return 1.0 / compute_exp(-x);
    }

    double term = 1.0;  // Первый член ряда: X^0 / 0! = 1
    double sum = 1.0;   // Начальное значение суммы
    int k = 1;          // Индекс текущего члена ряда
    
    // Добавляем члены ряда, пока они значимы
    while (term > 1e-12) {
        term *= x / k;  // Вычисляем следующий член ряда
        sum += term;    // Добавляем к сумме
        k++;
    }
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    double x;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x);
        printf("%0.15g\n", compute_exp(x));
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
