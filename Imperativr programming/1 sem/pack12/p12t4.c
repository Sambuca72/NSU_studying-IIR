#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Константы
#define MAX_NAME_LEN 30
#define MAX_COUNTRY_LEN 10
#define MAX_MOVIE_LEN 20
#define MAX_HASH_SIZE 200003 // Простое число для хеш-таблицы

// Структура для записи из таблицы ActorBio
typedef struct {
    char name[MAX_NAME_LEN + 1];
    int birthYear;
    char country[MAX_COUNTRY_LEN + 1];
} ActorBio;

// Структура для записи из таблицы ActorInMovie
typedef struct {
    char actorName[MAX_NAME_LEN + 1];
    char movieName[MAX_MOVIE_LEN + 1];
} ActorInMovie;

// Узел для хеш-таблицы
typedef struct HashNode {
    ActorBio actor;
    struct HashNode *next;
} HashNode;

// Хеш-функция (простая полиномиальная)
unsigned int hash(const char *key) {
    unsigned int h = 0;
    while (*key) {
        h = h * 31 + (unsigned char)(*key);
        key++;
    }
    return h % MAX_HASH_SIZE;
}

// Вставка в хеш-таблицу
void hash_insert(HashNode **hashTable, ActorBio *actor) {
    unsigned int h = hash(actor->name);
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->actor = *actor;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}

// Поиск в хеш-таблице
HashNode *hash_find(HashNode **hashTable, const char *key) {
    unsigned int h = hash(key);
    HashNode *current = hashTable[h];
    while (current) {
        if (strcmp(current->actor.name, key) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Очистка хеш-таблицы
void hash_free(HashNode **hashTable) {
    for (int i = 0; i < MAX_HASH_SIZE; i++) {
        HashNode *current = hashTable[i];
        while (current) {
            HashNode *tmp = current;
            current = current->next;
            free(tmp);
        }
    }
}

void read_quoted_string(char* dest) {
    char temp[128];
    scanf(" \"%[^\"]\"", temp);
    strncpy(dest, temp, strlen(temp) + 1);
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, m;

    // Считываем количество записей в ActorBio
    scanf("%d\n", &n);

    ActorBio *actorBio = (ActorBio *)malloc(n * sizeof(ActorBio));

    char line[100];
    for (int i = 0; i < n; i++) {
        read_quoted_string(actorBio[i].name);
        scanf("%d", &actorBio[i].birthYear);
        read_quoted_string(actorBio[i].country);
    }

    // Считываем количество записей в ActorInMovie
    scanf("%d\n", &m);

    ActorInMovie *actorInMovie = (ActorInMovie *)malloc(m * sizeof(ActorInMovie));

    for (int i = 0; i < m; i++) {
        read_quoted_string(actorInMovie[i].actorName);
        read_quoted_string(actorInMovie[i].movieName);
    }

    // Создаём хеш-таблицу
    HashNode *hashTable[MAX_HASH_SIZE] = {NULL};

    // Заполняем хеш-таблицу таблицей ActorBio
    for (int i = 0; i < n; i++) {
        hash_insert(hashTable, &actorBio[i]);
    }

    // Выполняем Inner Join
    for (int i = 0; i < m; i++) {
        HashNode *current = hash_find(hashTable, actorInMovie[i].actorName);
        while (current) {
            printf("\"%s\" %d \"%s\" \"%s\" \"%s\"\n",
                   current->actor.name,
                   current->actor.birthYear,
                   current->actor.country,
                   actorInMovie[i].actorName,
                   actorInMovie[i].movieName);
            current = current->next;
        }
    }

    // Очистка памяти
    hash_free(hashTable);
    free(actorBio);
    free(actorInMovie);
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}
