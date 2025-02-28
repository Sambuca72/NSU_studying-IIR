#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>л


void quicksort(int32_t* arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int32_t temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    quicksort(arr, left, j);
    quicksort(arr, i, right);
}

int main() {
    FILE* input = fopen("input.txt", "rb");
    FILE* output = fopen("output.txt", "wb");
    
    uint32_t N;
    fread(&N, sizeof(uint32_t), 1, input);

    int32_t* array = (int32_t*)malloc(N * sizeof(int32_t));

    fread(array, sizeof(int32_t), N, input) ;
    
    quicksort(array, 0, N - 1);

    fwrite(array, sizeof(int32_t), N, output);
    
    free(array);
    fclose(output);
    fclose(input);
    return 0;
}
