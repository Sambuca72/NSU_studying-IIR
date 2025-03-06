#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26 // Количество символов в алфавите
#define MOD 1000000007 // Большое простое число для модульной арифметики
#define BASE 31        // База для хеширования (выбрана произвольно)

typedef struct {
    unsigned long long hash_value;
    int color;
} HashTableEntry;

typedef struct {
    HashTableEntry *entries;
    int size;
    int capacity;
} HashTable;

// Функция для создания хэш-таблицы
HashTable *create_table(int capacity) {
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    table->entries = (HashTableEntry *)calloc(capacity, sizeof(HashTableEntry));
    table->size = 0;
    table->capacity = capacity;
    return table;
}

// Функция для добавления значения в хэш-таблицу
int hash_table_add(HashTable *table, unsigned long long hash_value, int *next_color) {
    int index = hash_value % table->capacity;
    while (table->entries[index].hash_value != 0) {
        if (table->entries[index].hash_value == hash_value) {
            return table->entries[index].color; // Уже существует
        }
        index = (index + 1) % table->capacity; // Разрешение коллизий
    }
    table->entries[index].hash_value = hash_value;
    table->entries[index].color = (*next_color)++;
    table->size++;
    return table->entries[index].color;
}

// Функция для вычисления хэша строки
unsigned long long compute_hash(const char *str, int length) {
    unsigned long long hash = 0;
    unsigned long long power = 1;
    for (int i = 0; i < length; i++) {
        hash = (hash + (str[i] - 'a' + 1) * power) % MOD;
        power = (power * BASE) % MOD;
    }
    return hash;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, B;
    scanf("%d %d", &N, &B);

    char S[N + 1];
    scanf("%s", S);

    HashTable *table = create_table(2 * N); // Хэш-таблица для хранения подстрок
    int next_color = 0;                     // Следующий доступный цвет

    unsigned long long current_hash = compute_hash(S, B);
    unsigned long long power = 1; // BASE^(B-1) для удаления первого символа

    for (int i = 1; i < B; i++) {
        power = (power * BASE) % MOD;
    }

    printf("%d", hash_table_add(table, current_hash, &next_color));

    for (int i = 1; i <= N - B; i++) {
        // Удаляем первый символ и добавляем следующий в скользящем хэше
        current_hash = (current_hash - (S[i - 1] - 'a' + 1) * power % MOD + MOD) % MOD;
        current_hash = (current_hash * BASE) % MOD;
        current_hash = (current_hash + (S[i + B - 1] - 'a' + 1)) % MOD;

        printf(" %d", hash_table_add(table, current_hash, &next_color));
    }

    printf("\n");

    // Очистка памяти
    free(table->entries);
    free(table);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
