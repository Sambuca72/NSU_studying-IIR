#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Константы для ограничений
#define MAX_NAME_LEN 30
#define MAX_COUNTRY_LEN 10
#define MAX_MOVIE_LEN 20


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

// Сравнение для qsort
int compare_actor_bio(const void *a, const void *b) {
    return strcmp(((ActorBio *)a)->name, ((ActorBio *)b)->name);
}

// Бинарный поиск для поиска первого совпадения
int binary_search(ActorBio *array, int size, const char *key) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        int cmp = strcmp(array[mid].name, key);
        if (cmp == 0) {
            // Найдено, двигаемся влево, чтобы найти самое левое совпадение
            while (mid > 0 && strcmp(array[mid - 1].name, key) == 0) {
                mid--;
            }
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Не найдено
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

    
    qsort(actorBio, n, sizeof(ActorBio), compare_actor_bio);

    // for(int i = 0;i<n;i++){
    //     printf("%s\n",actorBio[i].name);
    // }

    // Перебираем записи ActorInMovie
    for (int i = 0; i < m; i++) {
        const char *actorName = actorInMovie[i].actorName;

        // Находим первую запись с данным именем в ActorBio
        int index = binary_search(actorBio, n, actorName);

        // Если найдено, проходим по всем совпадающим записям
        if (index != -1) {
            for (int j = index; j < n && strcmp(actorBio[j].name, actorName) == 0; j++) {
                // Выводим соединённую запись
                printf("\"%s\" %d \"%s\" \"%s\" \"%s\"\n",
                       actorBio[j].name,
                       actorBio[j].birthYear,
                       actorBio[j].country,
                       actorInMovie[i].actorName,
                       actorInMovie[i].movieName);
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
