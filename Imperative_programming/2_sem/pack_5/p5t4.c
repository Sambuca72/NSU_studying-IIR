#include <stdio.h>
#include <stdlib.h>

#define MAXN 200001
#define MAXM 200001

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

int DFS(Graph* g, int u, int* visited, int* recStack, int* parent, int* cycle, int* cycleLen) {
    visited[u] = 1;
    recStack[u] = 1;

    Node* node = g->adj[u];
    while (node) {
        int v = node->vertex;
        if (!visited[v]) {
            parent[v] = u;
            if (DFS(g, v, visited, recStack, parent, cycle, cycleLen)) return 1;
        } else if (recStack[v]) {
            // Нашли цикл
            int cur = u;
            *cycleLen = 0;
            cycle[(*cycleLen)++] = v + 1; 
            while (cur != v) {
                cycle[(*cycleLen)++] = cur + 1;
                cur = parent[cur];
            }
            return 1;
        }
        node = node->next;
    }

    recStack[u] = 0;
    return 0;
}

int findCycle(Graph* g, int* cycle, int* cycleLen) {
    int* visited = (int*)calloc(g->V, sizeof(int));
    int* recStack = (int*)calloc(g->V, sizeof(int));
    int* parent = (int*)malloc(g->V * sizeof(int));

    for (int i = 0; i < g->V; i++) {
        parent[i] = -1;
    }

    for (int i = 0; i < g->V; i++) {
        if (!visited[i] && DFS(g, i, visited, recStack, parent, cycle, cycleLen)) {
            free(visited);
            free(recStack);
            free(parent);
            return 1;
        }
    }

    free(visited);
    free(recStack);
    free(parent);
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M;
    scanf("%d %d", &N, &M);

    Graph* g = createGraph(N); 

    for (int i = 0; i < M; i++) { 
        int from, where;
        scanf("%d %d", &from, &where);
        addVert(g, from, where);
    }

    int cycle[MAXN];
    int cycleLen = 0;

    if (findCycle(g, cycle, &cycleLen)) {
        printf("%d\n", cycleLen);
        for (int i = cycleLen - 1; i >= 0; i--) { 
            printf("%d ", cycle[i]);
        }
        printf("\n");
    } else {
        printf("-1\n");
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

    fclose(stdin);
    fclose(stdout);
    return 0;
}