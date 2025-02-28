#include <stdio.h>
#include <stdlib.h>

// Определение типа callback
typedef void (*callback)(void *ctx, int *value);

// Узел связного списка
typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Контекст для хранения суммы
typedef struct Context {
    int sum;
} Context;

// Callback функция для подсчёта суммы чётных чисел
void sumEvenCallback(void *ctx, int *value) {
    Context *context = (Context *)ctx;
    if (*value % 2 == 0) {
        context->sum += *value;
    }
}

// arrayForeach: обработка массива
void arrayForeach(void *ctx, callback func, int *arr, int n) {
    for (int i = 0; i < n; i++) {
        func(ctx, &arr[i]);
    }
}

// listForeach: обработка связного списка
void listForeach(void *ctx, callback func, Node *head) {
    Node *current = head;
    while (current != NULL) {
        func(ctx, &current->value);
        current = current->next;
    }
}

// Функция для создания узла связного списка
Node *createNode(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}


int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);    

    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        Node *node = createNode(arr[i]);
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    
    Context arrayCtx = {0};
    arrayForeach(&arrayCtx, sumEvenCallback, arr, n);

    
    Context listCtx = {0};
    listForeach(&listCtx, sumEvenCallback, head);

    
    printf("%d %d\n", arrayCtx.sum, listCtx.sum);

    
    free(arr);
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
