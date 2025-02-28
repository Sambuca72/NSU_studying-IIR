#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Узел для хеш-таблицы
typedef struct Node {
    uint64_t state;
    int index;
    struct Node* next;
} Node;

// Хеш-таблица
#define TABLE_SIZE 1000003 // Простое число для размера таблицы
Node* hash_table[TABLE_SIZE];

// Хеш-функция
uint64_t hash_function(uint64_t state) {
    return state % TABLE_SIZE;
}

// Вставка в хеш-таблицу
void insert(uint64_t state, int index) {
    uint64_t hash_index = hash_function(state);
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->state = state;
    new_node->index = index;
    new_node->next = hash_table[hash_index];
    hash_table[hash_index] = new_node;
}

// Поиск в хеш-таблице
int find(uint64_t state) {
    uint64_t hash_index = hash_function(state);
    Node* current = hash_table[hash_index];
    while (current) {
        if (current->state == state) {
            return current->index;
        }
        current = current->next;
    }
    return -1; // Не найдено
}

// Очистка хеш-таблицы
void clear_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hash_table[i];
        while (current) {
            Node* to_free = current;
            current = current->next;
            free(to_free);
        }
        hash_table[i] = NULL;
    }
}

// Основная функция
void find_cycle(uint64_t M, uint64_t a, uint64_t b, uint64_t c) {
    uint64_t state = 1;
    int index = 0;

    // Инициализация хеш-таблицы
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }

    // Поиск цикла
    while (1) {
        int previous_index = find(state);
        if (previous_index != -1) {
            // Цикл найден
            printf("%d %d\n", previous_index, index);
            break;
        }

        // Сохраняем текущее состояние
        insert(state, index);

        // Переход к следующему состоянию
        state = (state * state * a + state * b + c) % M;
        index++;
    }

    // Очистка памяти
    clear_table();
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    uint64_t M, a, b, c;

    // Чтение входных данных
    scanf("%lu", &M);
    scanf("%lu %lu %lu", &a, &b, &c);

    // Нахождение цикла
    find_cycle(M, a, b, c);

    return 0;

    fclose(stdin);
    fclose(stdout);
}
