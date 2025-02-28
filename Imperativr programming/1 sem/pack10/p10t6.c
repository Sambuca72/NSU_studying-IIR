#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 400
#define MAX_M 80000

typedef struct {
    int data[MAX_N + 1];
    int size;
} PriorityQueue;


void initQueue(PriorityQueue *pq) {
    pq->size = 0;
}


void push(PriorityQueue *pq, int value) {
    pq->data[++pq->size] = value;
    int i = pq->size;
    while (i > 1 && pq->data[i] < pq->data[i / 2]) {
        int temp = pq->data[i];
        pq->data[i] = pq->data[i / 2];
        pq->data[i / 2] = temp;
        i /= 2;
    }
}


int pop(PriorityQueue *pq) {
    int min = pq->data[1];
    pq->data[1] = pq->data[pq->size--];
    int i = 1;
    while (2 * i <= pq->size) {
        int smallest = i;
        if (pq->data[2 * i] < pq->data[smallest]) smallest = 2 * i;
        if (2 * i + 1 <= pq->size && pq->data[2 * i + 1] < pq->data[smallest]) smallest = 2 * i + 1;
        if (smallest == i) break;
        int temp = pq->data[i];
        pq->data[i] = pq->data[smallest];
        pq->data[smallest] = temp;
        i = smallest;
    }
    return min;
}


int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M;
    scanf("%d %d", &N, &M);

    
    int adj[MAX_N + 1][MAX_N + 1];
    int in_degree[MAX_N + 1];
    memset(adj, 0, sizeof(adj));
    memset(in_degree, 0, sizeof(in_degree));

    
    for (int i = 0; i < M; i++) {
        int B, A;
        scanf("%d %d", &B, &A);
        adj[B][A] = 1;
        in_degree[A]++;
    }

    
    PriorityQueue pq;
    initQueue(&pq);

    
    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0) {
            push(&pq, i);
        }
    }

    int result[MAX_N];
    int result_size = 0;

    // Алгоритм Кана
    while (!isEmpty(&pq)) {
        int current = pop(&pq);
        result[result_size++] = current;

        for (int neighbor = 1; neighbor <= N; neighbor++) {
            if (adj[current][neighbor]) {
                in_degree[neighbor]--;
                if (in_degree[neighbor] == 0) {
                    push(&pq, neighbor);
                }
            }
        }
    }

    
    if (result_size != N) {
        printf("bad course\n");
    } else {
        for (int i = 0; i < result_size; i++) {
            if (i > 0) printf(" ");
            printf("%d", result[i]);
        }
        printf("\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
