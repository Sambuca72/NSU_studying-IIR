#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_TABLE_SIZE 200003 // Размер хеш-таблицы (простое число для уменьшения коллизий)

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *hashTable[HASH_TABLE_SIZE];

// Функция хеширования
int hash(int x) {
    return (x % HASH_TABLE_SIZE + HASH_TABLE_SIZE) % HASH_TABLE_SIZE;
}

// Проверка наличия элемента в хеш-таблице
bool contains(int value) {
    int idx = hash(value);
    Node *current = hashTable[idx];
    while (current) {
        if (current->value == value) return true;
        current = current->next;
    }
    return false;
}

// Добавление элемента в хеш-таблицу
void add(int value) {
    int idx = hash(value);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if (!input || !output) {
        perror("Error opening file");
        return 1;
    }

    int n;
    fread(&n, sizeof(int), 1, input); 
    int *array = (int *)malloc(n * sizeof(int));
    fread(array, sizeof(int), n, input);

    int *result = (int *)malloc(n * sizeof(int));
    int resultCount = 0;

    
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    
    for (int i = 0; i < n; i++) {
        if (!contains(array[i])) {
            add(array[i]);
            result[resultCount++] = array[i];
        }
    }

    fwrite(&resultCount, sizeof(int), 1, output);
    fwrite(result, sizeof(int), resultCount, output);

    
    free(array);
    free(result);
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Node *current = hashTable[i];
        while (current) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
