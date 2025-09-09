#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef long long ll;

typedef struct Node {
    int vertex;
    ll weight;
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

void addNode(Graph* g, int u, int v, ll weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->next = g->adj[u];
    g->adj[u] = newNode;
}

void bellmanford(Graph* g, int start, ll *dist, int *nigative) {
    int V = g->V;

    for (int i = 0; i < V; i++) {
        dist[i] = LLONG_MAX;
    }
    dist[start] = 0;

    
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (Node* node = g->adj[u]; node; node = node->next) {
                int v = node->vertex;
                ll weight = node->weight;
                if (dist[u] != LLONG_MAX && dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
    
    
    for (int u = 0; u < V; u++) {
        for (Node* node = g->adj[u]; node; node = node->next) {
            int v = node->vertex;
            ll w = node->weight;
            if (dist[u] != LLONG_MAX && dist[v] > dist[u] + w) {
                nigative[v] = 1;
            }
        }
    }


    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (Node* node = g->adj[u]; node; node = node->next) {
                int v = node->vertex;
                if (nigative[u]) {
                    nigative[v] = 1;
                }
            }
        }
    }

    
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M, S;
    scanf("%d %d %d", &N, &M, &S);

    Graph *g = createGraph(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        ll w;
        scanf("%d %d %lld", &u, &v, &w);
        addNode(g, u - 1, v - 1, w); 
    }

    ll *dist = (ll*)malloc(N * sizeof(ll));
    int *nigative = (int*)calloc(N, sizeof(int));

    bellmanford(g, S - 1, dist, nigative);

    for (int i = 0; i < N; i++) {
        if (nigative[i]) {
            printf("-\n");
        } else if (dist[i] == LLONG_MAX) {
            printf("*\n");
        } else {
            printf("%lld\n", dist[i]);
        }
    }

    for (int i = 0; i < N; i++) {
        Node* node = g->adj[i];
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(g->adj);
    free(g);
    free(dist);
    free(nigative);

    fclose(stdin);
    fclose(stdout);
    return 0;
}