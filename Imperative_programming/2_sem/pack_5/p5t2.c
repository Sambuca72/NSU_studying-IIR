#include <stdio.h>
#include <stdlib.h>

#define MAX_V 200001

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
    g->adj = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++) {
        g->adj[i] = NULL;
    }
    return g;
}

void addVert(Graph* g, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v - 1; 
    newNode->next = g->adj[u - 1];
    g->adj[u - 1] = newNode;
}

void BFS(Graph* g, int* distance) {
    int* queue = (int*)malloc(sizeof(int) * g->V);
    int* visited = (int*)calloc(g->V, sizeof(int));
    int front = 0, back = 0;

    queue[back++] = 0; // Вершина 1 (индекс 0)
    visited[0] = 1;
    distance[0] = 0;

    while (front < back) {
        int u = queue[front++];
        Node* node = g->adj[u];
        while (node) {
            int v = node->vertex;
            if (!visited[v]) {
                visited[v] = 1;
                distance[v] = distance[u] + 1;
                queue[back++] = v;
            }
            node = node->next;
        }
    }

    free(queue);
    free(visited);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int M, N;
    scanf("%d %d", &M, &N);

    Graph* g = createGraph(M);

    for (int i = 0; i < N; i++) {
        int from, where;
        scanf("%d %d", &from, &where);
        addVert(g, from, where);
    }

    int* distance = (int*)malloc(M * sizeof(int));
    for (int i = 0; i < M; i++) {
        distance[i] = -1; 
    }

    BFS(g, distance);

    for (int i = 0; i < M; i++) {
        printf("%d\n", distance[i]);
    }

    free(distance);
    for (int i = 0; i < M; i++) {
        Node* node = g->adj[i];
        while (node) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(g->adj);
    free(g);

    fclose(stdin);
    fclose(stdout);
    return 0;
}