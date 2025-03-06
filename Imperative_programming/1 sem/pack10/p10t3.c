#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int head;
    int tail;
    int size;
    int capacity;
} CircularBuffer;

void initBuffer(CircularBuffer *buffer, int capacity) {
    buffer->data = (int *)malloc(capacity * sizeof(int));
    buffer->head = 0;
    buffer->tail = 0;
    buffer->size = 0;
    buffer->capacity = capacity;
}

void freeBuffer(CircularBuffer *buffer) {
    free(buffer->data);
}

int isEmpty(CircularBuffer *buffer) {
    return buffer->size == 0;
}

int isFull(CircularBuffer *buffer) {
    return buffer->size == buffer->capacity;
}

void pushFront(CircularBuffer *buffer, int value) {
    if (isFull(buffer)) return;  // Ignore overflow
    buffer->head = (buffer->head - 1 + buffer->capacity) % buffer->capacity;
    buffer->data[buffer->head] = value;
    buffer->size++;
}

void pushBack(CircularBuffer *buffer, int value) {
    if (isFull(buffer)) return;  // Ignore overflow
    buffer->data[buffer->tail] = value;
    buffer->tail = (buffer->tail + 1) % buffer->capacity;
    buffer->size++;
}

int popFront(CircularBuffer *buffer) {
    if (isEmpty(buffer)) return 0;  // Invalid case
    int value = buffer->data[buffer->head];
    buffer->head = (buffer->head + 1) % buffer->capacity;
    buffer->size--;
    return value;
}

int popBack(CircularBuffer *buffer) {
    if (isEmpty(buffer)) return 0;  // Invalid case
    buffer->tail = (buffer->tail - 1 + buffer->capacity) % buffer->capacity;
    int value = buffer->data[buffer->tail];
    buffer->size--;
    return value;
}

void printBuffer(CircularBuffer *buffer) {
    printf("%d", buffer->size);
    for (int i = 0, idx = buffer->head; i < buffer->size; i++, idx = (idx + 1) % buffer->capacity) {
        printf(" %d", buffer->data[idx]);
    }
    printf("\n");
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, m;
    scanf("%d %d", &n, &m);

    CircularBuffer left, right;
    initBuffer(&left, 2 * n + 1);
    initBuffer(&right, 2 * n + 1);

    for (int i = 1; i <= n; i++) {
        pushBack(&left, i);
        pushBack(&right, -i);
    }

    char operation;
    for (int i = 0; i < m; i++) {
        scanf(" %c", &operation);
        int op = (operation >= 'A') ? (operation - 'A' + 10) : (operation - '0');

        int takeFromRight = op & 8;
        int takeFromBottom = op & 4;
        int putToRight = op & 2;
        int putToBottom = op & 1;

        CircularBuffer *takeFrom = takeFromRight ? &right : &left;
        CircularBuffer *putTo = putToRight ? &right : &left;

        if (isEmpty(takeFrom)) continue;

        int card = takeFromBottom ? popBack(takeFrom) : popFront(takeFrom);

        if (putToBottom) {
            pushBack(putTo, card);
        } else {
            pushFront(putTo, card);
        }
    }

    printBuffer(&left);
    printBuffer(&right);

    freeBuffer(&left);
    freeBuffer(&right);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
