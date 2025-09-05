#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node** adj;
    int V;
} Graph;

Graph* createGraph(int V) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    g->adj = (Node**)malloc((V + 1) * sizeof(Node*));
    for (int i = 0; i <= V; i++) {
        g->adj[i] = NULL;
    }
    return g;
}

void addNode(Graph* g, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = g->adj[u];
    g->adj[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = u;
    newNode->next = g->adj[v];
    g->adj[v] = newNode;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void DFS(
    Graph *g, int u, int parent, 
    int *visited, int *disc, int *low, 
    int *is_articulation, int *time
) {
    visited[u] = 1;
    disc[u] = low[u] = (*time)++;
    int children = 0;

    Node* node = g->adj[u];
    while (node) {
        int v = node->vertex;

        if (v == parent) {
            node = node->next;
            continue;
        }

        if (!visited[v]) {
            children++;
            DFS(g, v, u, visited, disc, low, is_articulation, time);
            low[u] = min(low[u], low[v]);

            if (parent != -1 && low[v] >= disc[u]) {
                is_articulation[u] = 1;
            }
        } else {
            low[u] = min(low[u], disc[v]);
        }

        node = node->next;
    }


    if (parent == -1 && children >= 2) {
        is_articulation[u] = 1;
    }
}

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M;
    scanf("%d %d", &N, &M);

    Graph *g = createGraph(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u == v) continue; 
        addNode(g, u, v);
    }

    int *visited = (int*)calloc(N + 1, sizeof(int));
    int *disc = (int*)calloc(N + 1, sizeof(int));
    int *low = (int*)calloc(N + 1, sizeof(int));
    int *is_articulation = (int*)calloc(N + 1, sizeof(int));
    int time = 0;

    for (int u = 1; u <= N; u++) {
        if (!visited[u]) {
            DFS(g, u, -1, visited, disc, low, is_articulation, &time);
        }
    }

    // Собираем результат
    int count = 0;
    for (int u = 1; u <= N; u++) {
        if (is_articulation[u]) {
            count++;
        }
    }

    printf("%d\n", count);

    for (int u = 1; u <= N; u++) {
        if (is_articulation[u]) {
            printf("%d ", u);
        }
    }


    for (int u = 1; u <= N; u++) {
        Node* node = g->adj[u];
        while (node) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(g->adj);
    free(g);
    free(visited);
    free(disc);
    free(low);
    free(is_articulation);

    fclose(stdin);
    fclose(stdout);
    return 0;
}