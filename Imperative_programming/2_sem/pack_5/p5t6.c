#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX_V 301

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

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = u;
    newNode->weight = w;
    newNode->next = g->adj[v];
    g->adj[v] = newNode;
}

void dijkstra(Graph* g, int start, int *dist, int *prev) {
    int visited[MAX_V] = {0};

    for(int i = 1; i <= g->V; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }
    dist[start] = 0;

    for(int count = 0; count < g->V; count++) {
        int u = -1;
        for(int v = 1; v <= g->V; v++) {
            if(!visited[v] && (u == -1 || dist[v] < dist[u])) {
                u = v;
            }
        }

        if(u == -1 || dist[u] == INT_MAX) break;

        visited[u] = 1;

        Node* node = g->adj[u];
        while(node != NULL) {
            int v = node->vertex;
            int weight = node->weight;
            if(!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
            }
            node = node->next;
        }
    }
}

void printPath(int *prev, int v, FILE *out) {
    if(prev[v] == -1) {
        fprintf(out, " %d", v);
        return;
    }
    printPath(prev, prev[v], out);
    fprintf(out, " %d", v);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M, P, K;
    scanf("%d %d %d %d", &N, &M, &P, &K);

    Graph* G = createGraph(N);

    for(int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(G, u, v, w);
    }

    for(int i = 0; i < P + K; i++) {
        int S, T;
        scanf("%d %d", &S, &T);

        int dist[MAX_V];
        int prev[MAX_V];
        dijkstra(G, S, dist, prev);

        if(i < P) {
            printf("%d", dist[T]);

            int count = 0;
            for(int v = T; v != -1; v = prev[v]) {
                count++;
            }
            printf(" %d", count);

            printPath(prev, T, stdout);
            printf("\n");
        } else {
            printf("%d\n", dist[T]);
        }
    }

    for(int i = 1; i <= N; i++) {
        Node* node = G->adj[i];
        while(node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(G->adj);
    free(G);

    fclose(stdin);
    fclose(stdout);
}