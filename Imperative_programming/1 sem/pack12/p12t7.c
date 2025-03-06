#include <stdio.h>
#include <stdlib.h>

#define MAXN 200000

// Двусторонняя очередь для хранения индексов
typedef struct {
    int data[MAXN];
    int front, back;
} Deque;

// Инициализация дека
void initDeque(Deque *dq) {
    dq->front = 0;
    dq->back = 0;
}

// Проверка, пуст ли дек
int isEmpty(Deque *dq) {
    return dq->front == dq->back;
}

// Добавление элемента в конец дека
void pushBack(Deque *dq, int value) {
    dq->data[dq->back++] = value;
}

// Удаление элемента из начала дека
void popFront(Deque *dq) {
    if (!isEmpty(dq)) {
        dq->front++;
    }
}

// Удаление элемента из конца дека
void popBack(Deque *dq) {
    if (!isEmpty(dq)) {
        dq->back--;
    }
}

// Получение элемента из начала дека
int front(Deque *dq) {
    return dq->data[dq->front];
}

// Получение элемента из конца дека
int back(Deque *dq) {
    return dq->data[dq->back - 1];
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    scanf("%d", &n);

    int arr[MAXN];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    char commands[2 * MAXN];
    scanf("%s", commands);

    Deque dq;
    initDeque(&dq);

    int l = 0, r = 0; // Начальные границы окна

    for (int i = 0; commands[i] != '\0'; i++) {
        if (commands[i] == 'R') {
            // Увеличиваем правую границу
            r++;

            // Удаляем из конца дека элементы, которые меньше текущего
            while (!isEmpty(&dq) && arr[back(&dq)] <= arr[r - 1]) {
                popBack(&dq);
            }

            // Добавляем текущий элемент в конец дека
            pushBack(&dq, r - 1);

        } else if (commands[i] == 'L') {
            // Увеличиваем левую границу
            l++;

            // Удаляем из начала дека элементы, которые выходят за левую границу
            if (!isEmpty(&dq) && front(&dq) < l) {
                popFront(&dq);
            }
        }

        
        printf("%d\n", arr[front(&dq)]);
    }

    return 0;
    fclose(stdin);
    fclose(stdout);
}
