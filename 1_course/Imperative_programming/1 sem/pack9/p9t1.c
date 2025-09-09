#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Функция для слияния двух отсортированных массивов
int merge(const int32_t *a, int32_t ak, const int32_t *b, int32_t bk, int32_t *res) {
    int32_t i = 0, j = 0, k = 0;

    // Сливаем элементы массивов
    while (i < ak && j < bk) {
        if (a[i] <= b[j]) {
            res[k++] = a[i++];
        } else {
            res[k++] = b[j++];
        }
    }

    // Копируем оставшиеся элементы из массива `a`
    while (i < ak) {
        res[k++] = a[i++];
    }

    // Копируем оставшиеся элементы из массива `b`
    while (j < bk) {
        res[k++] = b[j++];
    }

    return k; // Возвращаем размер результирующего массива
}

int main() {
    FILE *input = fopen("input.txt", "rb");
    FILE *output = fopen("output.txt", "wb");



    // Чтение размеров массивов
    int32_t N, M;
    fread(&N, sizeof(int32_t), 1, input);
    fread(&M, sizeof(int32_t), 1, input);

    // Выделяем память для массивов
    int32_t *a = (int32_t *)malloc(N * sizeof(int32_t));
    int32_t *b = (int32_t *)malloc(M * sizeof(int32_t));
    int32_t *res = (int32_t *)malloc((N + M) * sizeof(int32_t));


    // Чтение массивов из входного файла
    fread(a, sizeof(int32_t), N, input);
    fread(b, sizeof(int32_t), M, input);

    // Выполняем слияние
    int32_t result_size = merge(a, N, b, M, res);


    fwrite(res, sizeof(int32_t), result_size, output);


    free(a);
    free(b);
    free(res);
    fclose(input);
    fclose(output);

    return 0;
}
