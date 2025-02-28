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

// Узел дерева поиска
typedef struct TreeNode {
    ActorBio actor;
    struct TreeNode *left, *right;
} TreeNode;

// Функция для создания нового узла дерева
TreeNode* createNode(ActorBio actor) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->actor = actor;
    node->left = node->right = NULL;
    return node;
}

// Вставка в дерево поиска
TreeNode* insert(TreeNode* root, ActorBio actor) {
    if (!root) return createNode(actor);
    if (strcmp(actor.name, root->actor.name) < 0) {
        root->left = insert(root->left, actor);
    } else {
        root->right = insert(root->right, actor);
    }
    return root;
}

// Поиск в дереве
TreeNode* search(TreeNode* root, const char* name) {
    if (!root || strcmp(name, root->actor.name) == 0) return root;
    if (strcmp(name, root->actor.name) < 0) {
        return search(root->left, name);
    }
    return search(root->right, name);
}

// Очистка дерева
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Функция для считывания строки в кавычках
void read_quoted_string(char* dest) {
    char temp[128];
    scanf(" \"%[^\"]\"", temp);
    strncpy(dest, temp, strlen(temp) + 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

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

    // Строим дерево поиска из таблицы ActorBio
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, actorBio[i]);
    }

    // Выполняем Inner Join
    for (int i = 0; i < m; i++) {
        TreeNode* node = search(root, actorInMovie[i].actorName);
        if (node) {
            printf("\"%s\" %d \"%s\" \"%s\" \"%s\"\n",
                   node->actor.name,
                   node->actor.birthYear,
                   node->actor.country,
                   actorInMovie[i].actorName,
                   actorInMovie[i].movieName);
        }
    }

    // Очистка памяти
    freeTree(root);
    fclose(stdin);
    fclose(stdout);

    return 0;
}
