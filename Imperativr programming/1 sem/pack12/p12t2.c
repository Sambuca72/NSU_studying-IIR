#include <stdio.h>
#include <stdlib.h>

// Структура узла дерева
typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

// Функция для создания нового узла
Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

// Вставка элемента в дерево
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return create_node(value);
    }
    if (value == root->value) {
        // Если равны, выбираем направление случайно
        if (rand() % 2 == 0) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }
    } else if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Обход дерева (in-order) и заполнение массива
void inorder_traversal(Node* root, int* arr, int* index) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left, arr, index);
    arr[(*index)++] = root->value;
    inorder_traversal(root->right, arr, index);
}

// Освобождение памяти дерева
void free_tree(Node* root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    int n;
    fread(&n, sizeof(int), 1, input);

    int* arr = (int*)malloc(n * sizeof(int));

    fread(arr, sizeof(int), n, input);

    // Строим дерево поиска
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    
    int index = 0;
    inorder_traversal(root, arr, &index);

    
    fwrite(arr, sizeof(int), n, output);

    
    free(arr);
    free_tree(root);
    fclose(input);
    fclose(output);

    return 0;
}
