#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для вычисления модуля
long long mod(long long r, long long a) {
    return (((r % a) + a) % a);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "No parameters specified.");
        return 13;
    }

    char *op;
    long long num1, num2, m = 0;
    int use_mod = 0; // Флаг для использования модуля

    // Проверяем, есть ли параметр -m
    if (argc == 6 && strcmp(argv[4], "-m") == 0) {
        use_mod = 1;
        op = argv[1];
        num1 = atoll(argv[2]);
        num2 = atoll(argv[3]);
        m = atoll(argv[5]);
    } else if (argc == 6 && strcmp(argv[1], "-m") == 0) {
        use_mod = 1;
        m = atoll(argv[2]);
        op = argv[3];
        num1 = atoll(argv[4]);
        num2 = atoll(argv[5]);
    } else if (argc == 4) {
        op = argv[1];
        num1 = atoll(argv[2]);
        num2 = atoll(argv[3]);
    }

    long long result;

 
    if (strcmp(op, "mul") == 0) {
        result = num1 * num2;
    } else if (strcmp(op, "add") == 0) {
        result = num1 + num2;
    } else if (strcmp(op, "sub") == 0) {
        result = num1 - num2;
    }

    if (use_mod) {
        result = mod(result, m);
    }

    printf("%lld", result);

    return 0;
}