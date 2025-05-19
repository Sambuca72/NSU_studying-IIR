#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node** adj;
    int* in_degree;
    int V;
} Graph;

Graph* createGraph(int V) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    g->adj = (Node**)malloc(V * sizeof(Node*));
    g->in_degree = (int*)calloc(V, sizeof(int));
    for (int i = 0; i < V; i++) {
        g->adj[i] = NULL;
    }
    return g;
}

void addNode(Graph* g, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = g->adj[u];
    g->adj[u] = newNode;
    g->in_degree[v]++;
}

int* topologicalSort(Graph* g) {
    int* order = (int*)malloc(g->V * sizeof(int));
    int* queue = (int*)malloc(g->V * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < g->V; i++) {
        if (g->in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int idx = 0;
    while (front < rear) {
        int u = queue[front++];
        order[idx++] = u;

        Node* node = g->adj[u];
        while (node != NULL) {
            int v = node->vertex;
            g->in_degree[v]--;
            if (g->in_degree[v] == 0) {
                queue[rear++] = v;
            }
            node = node->next;
        }
    }

    free(queue);

    if (idx != g->V) {
        free(order);
        return NULL;
    }

    return order;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    scanf("%d %d", &n, &m);

    Graph* g = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addNode(g, u - 1, v - 1);
    }

    int* order = topologicalSort(g);

    if (order == NULL) {
        printf("NO\n");
    } else {
        int* result = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            result[order[i]] = i + 1;
        }
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
    }

    free(order);

    for (int i = 0; i < n; i++) {
        Node* node = g->adj[i];
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(g->adj);
    free(g->in_degree);
    free(g);

    fclose(stdin);
    fclose(stdout);
    return 0;
}