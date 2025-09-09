#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int size, capacity;
} List;

// Инициализация списка
void initList(List *list) {
    list->size = 0;
    list->capacity = 2;
    list->data = (int *)malloc(list->capacity * sizeof(int));
}

// Добавление элемента в список
void addToList(List *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = value;
}

// Очистка списка
void freeList(List *list) {
    free(list->data);
}

// Приоритетная очередь на базе массива
typedef struct {
    int *data;
    int size;
    int capacity;
} PriorityQueue;

// Инициализация очереди
void initQueue(PriorityQueue *pq, int capacity) {
    pq->data = (int *)malloc(capacity * sizeof(int));
    pq->size = 0;
    pq->capacity = capacity;
}

// Добавление элемента в очередь
void push(PriorityQueue *pq, int value) {
    pq->data[pq->size++] = value;
    int i = pq->size - 1;
    while (i > 0 && pq->data[(i - 1) / 2] > pq->data[i]) {
        int temp = pq->data[i];
        pq->data[i] = pq->data[(i - 1) / 2];
        pq->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Удаление минимального элемента из очереди
int pop(PriorityQueue *pq) {
    int minValue = pq->data[0];
    pq->data[0] = pq->data[--pq->size];
    int i = 0;
    while (2 * i + 1 < pq->size) {
        int smallest = i;
        if (pq->data[2 * i + 1] < pq->data[smallest]) {
            smallest = 2 * i + 1;
        }
        if (2 * i + 2 < pq->size && pq->data[2 * i + 2] < pq->data[smallest]) {
            smallest = 2 * i + 2;
        }
        if (smallest == i) break;
        int temp = pq->data[i];
        pq->data[i] = pq->data[smallest];
        pq->data[smallest] = temp;
        i = smallest;
    }
    return minValue;
}

// Проверка на пустоту
bool isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

// Освобождение памяти очереди
void freeQueue(PriorityQueue *pq) {
    free(pq->data);
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, m;
    scanf("%d %d", &n, &m);

    List *adj = (List *)malloc((n + 1) * sizeof(List));
    for (int i = 1; i <= n; i++) {
        initList(&adj[i]);
    }

    int *inDegree = (int *)calloc(n + 1, sizeof(int));

    for (int i = 0; i < m; i++) {
        int b, a;
        scanf("%d %d", &b, &a);
        addToList(&adj[b], a);
        inDegree[a]++;
    }

    // Приоритетная очередь для вершин с нулевой входящей степенью
    PriorityQueue pq;
    initQueue(&pq, n);

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            push(&pq, i);
        }
    }

    int *sorted = (int *)malloc(n * sizeof(int));
    int index = 0;

    // Алгоритм Кана
    while (!isEmpty(&pq)) {
        int curr = pop(&pq);
        sorted[index++] = curr;

        for (int i = 0; i < adj[curr].size; i++) {
            int neighbor = adj[curr].data[i];
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                push(&pq, neighbor);
            }
        }
    }

    // Проверка на цикл
    if (index != n) {
        printf("bad course\n");
    } else {
        for (int i = 0; i < index; i++) {
            printf("%d ", sorted[i]);
        }
        printf("\n");
    }

    
    for (int i = 1; i <= n; i++) {
        freeList(&adj[i]);
    }
    free(adj);
    free(inDegree);
    free(sorted);
    freeQueue(&pq);

    fclose(stdin);
    fclose(stdout);

    return 0;
}
