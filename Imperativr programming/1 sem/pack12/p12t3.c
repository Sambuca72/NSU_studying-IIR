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

    // Выполняем Inner Join
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (strcmp(actorBio[i].name, actorInMovie[j].actorName) == 0) {
                // Если совпадают имена, выводим результат
                // printf("%s %s\n",actorBio[i].name,actorInMovie[j].actorName);
                printf("\"%s\" %d \"%s\" \"%s\" \"%s\"\n",
                       actorBio[i].name,
                       actorBio[i].birthYear,
                       actorBio[i].country,
                       actorInMovie[j].actorName,
                       actorInMovie[j].movieName);
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
