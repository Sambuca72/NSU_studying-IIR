#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX_V 5001

typedef struct Node {
    int vertex;
    int weight;
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

void addEdge(Graph* g, int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = g->adj[u];
    g->adj[u] = newNode;
}

void bellmanford(Graph* g, int start, int *dist, int *prev) {
    int V = g->V;

    for (int i = 1; i <= V; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }
    dist[start] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int u = 1; u <= V; u++) {
            Node* curr = g->adj[u];
            while (curr != NULL) {
                int v = curr->vertex;
                int weight = curr->weight;
                if (dist[u] != INT_MAX && dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                }
                curr = curr->next;
            }
        }
    }
}

void printPath(int *prev, int v, FILE *out) {
    if (prev[v] == -1) {
        fprintf(out, " %d", v);
        return;
    }
    printPath(prev, prev[v], out);
    fprintf(out, " %d", v);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    Graph* G = createGraph(N);
    int *friends = (int*)calloc(MAX_V, sizeof(int));
    int friends_order[K];

    for (int i = 0; i < K; i++) {
        scanf("%d", &friends_order[i]);
        friends[friends_order[i]] = 1;
    }

    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(G, u, v, w);
    }

    int dist[MAX_V];
    int prev[MAX_V];
    bellmanford(G, 1, dist, prev);

    for (int i = 0; i < K; i++) {
        int v = friends_order[i];
        printf("%d", dist[v]);

        int count = 0;
        for (int u = v; u != -1; u = prev[u]) {
            count++;
        }
        printf(" %d", count);

        printPath(prev, v, stdout);
        printf("\n");
    }

    for (int i = 1; i <= N; i++) {
        Node* node = G->adj[i];
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(G->adj);
    free(G);
    free(friends);

    fclose(stdin);
    fclose(stdout);
    return 0;
}