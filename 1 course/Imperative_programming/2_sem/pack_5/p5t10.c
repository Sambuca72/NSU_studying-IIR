#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex, num;
    struct Node* next;
} Node;

typedef struct {
    Node** adj;
    int V;
} Graph;

typedef struct {
    int u, v;
} Edge;

int bridge_num = 0;

Graph* createGraph(int V) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    g->adj = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++) {
        g->adj[i] = NULL;
    }
    return g;
}

void addNode(Graph* g, int u, int v, int num) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->num = num;
    newNode->next = g->adj[u];
    g->adj[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = u;
    newNode->num = num;
    newNode->next = g->adj[v];
    g->adj[v] = newNode;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void DFS(Graph *g, int u, int parent, int *visited, int *disc, int *low, int *bridges, int *time, Edge *edges, int *multi) {
    visited[u] = 1;
    disc[u] = low[u] = (*time)++;

    Node* node = g->adj[u];
    while (node) {
        int v = node->vertex;

        if (v == parent) {
            node = node->next;
            continue;
        }

        if (!visited[v]) {
            DFS(g, v, u, visited, disc, low, bridges, time, edges, multi);
            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u]) {
                int a = edges[node->num].u;
                int b = edges[node->num].v;
                if (a > b) { int tmp = a; a = b; b = tmp; }

                if (multi[a * g->V + b] == 1) {
                    bridges[node->num] = 1;
                    bridge_num++;
                }
            }
        } else {
            low[u] = min(low[u], disc[v]);
        }

        node = node->next;
    }
}

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M;
    scanf("%d %d", &N, &M);

    Graph *g = createGraph(N);
    Edge* edges = (Edge*)malloc(M * sizeof(Edge));
    int* multi = (int*)calloc(N * N, sizeof(int));

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        edges[i].u = u;
        edges[i].v = v;

        if (u == v) continue;

        int a = u, b = v;
        if (a > b) { int tmp = a; a = b; b = tmp; }

        multi[a * N + b]++;
    }

    
    for (int i = 0; i < M; i++) {
        int u = edges[i].u, v = edges[i].v;
        if (u == v) continue;

        int a = u, b = v;
        if (a > b) { int tmp = a; a = b; b = tmp; }

        if (multi[a * N + b]) {
            addNode(g, u, v, i);
            multi[a * N + b] = -multi[a * N + b]; 
        }
    }

    for (int i = 0; i < N * N; i++) {
        if (multi[i] < 0) multi[i] = -multi[i];
    }

    int *visited = (int*)calloc(N, sizeof(int));
    int *disc = (int*)calloc(N, sizeof(int));
    int *low = (int*)calloc(N, sizeof(int));
    int *bridges = (int*)calloc(M, sizeof(int));
    int time = 0;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            DFS(g, i, -1, visited, disc, low, bridges, &time, edges, multi);
        }
    }

    int *result = (int*)malloc(bridge_num * sizeof(int));
    int idx = 0;
    for (int i = 0; i < M; i++) {
        if (bridges[i]) {
            result[idx++] = i + 1;
        }
    }

    qsort(result, bridge_num, sizeof(int), cmp);

    printf("%d\n", bridge_num);
    for (int i = 0; i < bridge_num; i++) {
        printf("%d ", result[i]);
    }


    for (int i = 0; i < N; i++) {
        Node* node = g->adj[i];
        while (node) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(g->adj);
    free(g);
    free(edges);
    free(multi);
    free(visited);
    free(disc);
    free(low);
    free(bridges);
    free(result);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
