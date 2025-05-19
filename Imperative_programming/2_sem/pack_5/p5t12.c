#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define INF 1e18

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
    newNode->vertex = v - 1;
    newNode->weight = weight;
    newNode->next = g->adj[u - 1];
    g->adj[u - 1] = newNode;
}

void dfs(Graph* g, int u, int* reachable_from_neg) {
    reachable_from_neg[u] = 1;
    for (Node* node = g->adj[u]; node; node = node->next) {
        int v = node->vertex;
        if (!reachable_from_neg[v]) {
            dfs(g, v, reachable_from_neg);
        }
    }
}

void bellmanford(Graph* g, int start, ll *dist, int *nigative) {
    int V = g->V;

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (Node* node = g->adj[u]; node; node = node->next) {
                int v = node->vertex;
                ll weight = node->weight;
                if (dist[u] != INF && dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
    
    for (int u = 0; u < V; u++) {
        for (Node* node = g->adj[u]; node; node = node->next) {
            int v = node->vertex;
            ll w = node->weight;
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                nigative[v] = 1;
            }
        }
    }

    
    for(int i = 0; i < V - 1; i++){
        for (int u = 0; u < V; u++) {
            for (Node* node = g->adj[u]; node; node = node->next) {
                int v = node->vertex;
                if (nigative[u]) {
                    nigative[v] = 1;
                }
            }
        }
    }

    
    

    // for (int i = 1; i <= g->V; i++) {
    //     if (negative[i] && !reachable_from_neg[i]) {
    //         dfs(g, i, reachable_from_neg);
    //     }
    // }



}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M, S;
    scanf("%d %d %d", &N, &M, &S);

    Graph *g = createGraph(N);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addNode(g, u, v, w);
    }

    ll *dist = (ll*)malloc((N) * sizeof(ll));
    int *nigative = (int*)calloc(N, sizeof(int));
    // int *reach_from_nigative = (int*)calloc(N + 1, sizeof(int));
    // int prev[MAX_V];
    bellmanford(g, S - 1, dist, nigative);

    for(int i = 0; i < N; i++) {
        if(nigative[i]) {
            printf("-\n");
        } else if(dist[i] == INF) {
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
    // free(reach_from_nigative);


    fclose(stdin);
    fclose(stdout);
    return 0;
}