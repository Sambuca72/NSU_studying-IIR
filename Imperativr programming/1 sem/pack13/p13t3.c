#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 300000


int set[MAX_SIZE];
int size = 0;

// Функция для бинарного поиска (для операции lower)
int binary_search(int v) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (set[mid] == v) {
            return mid;
        } else if (set[mid] < v) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

// Функция для добавления числа в множество
void add(int v) {
    int pos = binary_search(v);
    if (pos < size && set[pos] == v) {
        printf("dupe\n");
    } else {
        // Сдвигаем элементы вправо, чтобы вставить v
        for (int i = size; i > pos; --i) {
            set[i] = set[i - 1];
        }
        set[pos] = v;
        size++;
        printf("added\n");
    }
}

// Функция для удаления числа из множества
void remove_value(int v) {
    int pos = binary_search(v);
    if (pos < size && set[pos] == v) {
        // Сдвигаем элементы влево
        for (int i = pos; i < size - 1; ++i) {
            set[i] = set[i + 1];
        }
        size--;
        printf("removed\n");
    } else {
        printf("miss\n");
    }
}

// Функция для поиска минимального элемента, который >= v
void lower(int v) {
    int pos = binary_search(v);
    if (pos < size) {
        printf("%d\n", set[pos]);
    } else {
        printf("###\n");
    }
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int M;
    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        char operation[7];
        int value;
        scanf("%s %d", operation, &value);

        if (operation[0] == 'a') {  // add
            add(value);
        } else if (operation[0] == 'r') {  // remove
            remove_value(value);
        } else if (operation[0] == 'l') {  // lower
            lower(value);
        }
    }

    return 0;
    fclose(stdin);
    fclose(stdout);
}
