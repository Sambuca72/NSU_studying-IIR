#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Константы для ограничений
#define MAX_NAME_LEN 30
#define MAX_COUNTRY_LEN 10
#define MAX_MOVIE_LEN 20
#define MAX_RECORDS 100000

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

// Функция для считывания строки в кавычках
void read_quoted_string(char* dest) {
    char temp[128];
    scanf(" \"%[^\"]\"", temp);
    strncpy(dest, temp, strlen(temp) + 1);
}

//Функция для сортировки ActorBio
int compare_actor_bio(const void *a, const void *b) {
    return strcmp(((ActorBio *)a)->name, ((ActorBio *)b)->name);
}

// Функция для сортировки ActorInMovie
int compare_actor_in_movie(const void *a, const void *b) {
    return strcmp(((ActorInMovie *)a)->actorName, ((ActorInMovie *)b)->actorName);
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m;
    
    // Считываем количество записей в ActorBio
    scanf("%d", &n);

    ActorBio actorBio[n];
    for (int i = 0; i < n; i++) {
        read_quoted_string(actorBio[i].name);
        scanf("%d", &actorBio[i].birthYear);
        read_quoted_string(actorBio[i].country);
    }

    // Считываем количество записей в ActorInMovie
    scanf("%d", &m);

    ActorInMovie actorInMovie[m];
    for (int i = 0; i < m; i++) {
        read_quoted_string(actorInMovie[i].actorName);
        read_quoted_string(actorInMovie[i].movieName);
    }

    // Сортируем обе таблицы
    qsort(actorBio, n, sizeof(ActorBio), compare_actor_bio);
    qsort(actorInMovie, m, sizeof(ActorInMovie), compare_actor_in_movie);

    
    int i = 0, j = 0;

    // Основной цикл слияния
    while (i < n && j < m) {
        int cmp = strcmp(actorBio[i].name, actorInMovie[j].actorName);

        if (cmp == 0) {
            // Группы совпадают, собираем все записи с одинаковым именем
            int start_i = i, start_j = j;

            // Найти конец группы в первой таблице
            while (i < n && strcmp(actorBio[i].name, actorBio[start_i].name) == 0) {
                i++;
            }

            // Найти конец группы во второй таблице
            while (j < m && strcmp(actorInMovie[j].actorName, actorInMovie[start_j].actorName) == 0) {
                j++;
            }

            // Объединяем все записи из двух групп
            for (int x = start_i; x < i; x++) {
                for (int y = start_j; y < j; y++) {
                    printf("\"%s\" %d \"%s\" \"%s\" \"%s\"\n",
                           actorBio[x].name,
                           actorBio[x].birthYear,
                           actorBio[x].country,
                           actorInMovie[y].actorName,
                           actorInMovie[y].movieName);
                }
            }
        } else if (cmp < 0) {
            i++;
        } else {
            j++;
        }
    }
    // printf("penis");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
