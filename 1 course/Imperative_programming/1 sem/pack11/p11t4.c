#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Функция lower_bound
int lower_bound(void *arr, size_t n, size_t size, void *key, int (*cmp)(const void *, const void *)) {
    size_t left = 0, right = n;
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        void *midElem = (char *)arr + mid * size; // Указатель на mid элемент
        if (cmp(midElem, key) < 0) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return (int)left;
}

// Компаратор для целых чисел
int compare_int(const void *a, const void *b) {
    int64_t int_a = *(const int64_t *)a;
    int64_t int_b = *(const int64_t *)b;
    if (int_a < int_b)
        return -1;
    if (int_a > int_b)
        return 1;
    return 0; // Равенство
}


// Компаратор для строк
int compare_str(const void *a, const void *b) {
    const char *str_a = *(const char **)a; 
    const char *str_b = *(const char **)b;
    return strcmp(str_a, str_b);
}


int main(void){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    // printf("1\n");
    int n1;
    scanf("%d",&n1);
    // printf("1\n");
    int64_t *arr1 = (int64_t *)malloc(sizeof(int64_t)*n1);

    for(int i = 0;i<n1;i++){
        scanf("%lld",&arr1[i]);
    }

    qsort(arr1, n1, sizeof(int64_t), compare_int);

    int n2;
    scanf("%d",&n2);

    char **arr2 = (char **)malloc(sizeof(char *)*n2);

    for(int i = 0;i<n2;i++){
        arr2[i]=(char *)malloc(sizeof(char) * 32);
        scanf("%s",arr2[i]);
    }

    qsort(arr2, n2, sizeof(char *), compare_str);

    // for(int i = 0;i<n1;i++){
    //     printf("%lld\n",arr1[i]);
    // }


    // for(int i = 0;i<n2;i++){
    //     printf("%s",arr2[i]);
    // }

    int q1;
    scanf("%d", &q1);
    for (int i = 0; i < q1; i++) {
        int64_t query;
        scanf("%lld", &query);
        int result = lower_bound(arr1, n1, sizeof(int64_t), &query, compare_int);
        printf("%d\n", result);
    }

    // // Обработка запросов для строк
     int q2;
    scanf("%d", &q2);
    for (int i = 0; i < q2; i++) {
        char query[32];
        scanf("%s", query);
        char *key = query;
        int result = lower_bound(arr2, n2, sizeof(char *), &key, compare_str);
        printf("%d\n", result);
    }

    // Очистка памяти
    free(arr1);
    for (int i = 0; i < n2; i++) {
        free(arr2[i]);
    }
    free(arr2);


    fclose(stdin);
    fclose(stdout);
}