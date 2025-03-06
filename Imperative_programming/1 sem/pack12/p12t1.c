#include <stdio.h>
#include <stdlib.h>

// Вспомогательная функция для обмена элементов
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Функция для просеивания вниз 
void heapify(int *arr, int n, int i) {
    int largest = i; // Изначально корень — наибольший элемент
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Проверяем левый дочерний элемент
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Проверяем правый дочерний элемент
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Если наибольший элемент не корень, меняем их местами и продолжаем
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Алгоритм сортировки кучей
void heapSort(int *arr, int n) {
    // Построение кучи
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Извлечение элементов из кучи
    for (int i = n - 1; i >= 0; i--) {
        // Перемещаем текущий корень (наибольший элемент) в конец
        swap(&arr[0], &arr[i]);

        // Вызываем heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");


    int n;
    fread(&n, sizeof(int), 1, input);


    
    int *arr = (int *)malloc(n * sizeof(int));
    

    
    fread(arr, sizeof(int), n, input);

    
    heapSort(arr, n);

    
    fwrite(arr, sizeof(int), n, output);

    
    free(arr);
    fclose(input);
    fclose(output);

    return 0;
}
