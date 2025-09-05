#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 105
#define INF 1000000000

typedef struct Node {
    int vertex;
    int capacity;
    int flow;
    struct Node* next;
    struct Node* rev;
} Node;

typedef struct {
    Node** adj;
    int V;
} Graph;

int visited_cut[MAXN];
int visited_dfs[MAXN];
int edges_u[MAXN * MAXN], edges_v[MAXN * MAXN], edges_c[MAXN * MAXN], edge_id = 0;

Graph* createGraph(int V) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    g->adj = (Node**)malloc((V + 1) * sizeof(Node*));
    for (int i = 0; i <= V; i++) g->adj[i] = NULL;
    return g;
}

void addEdge(Graph* g, int u, int v, int w) {
    Node* a = (Node*)malloc(sizeof(Node));
    Node* b = (Node*)malloc(sizeof(Node));
    a->vertex = v; a->capacity = w; a->flow = 0; a->next = g->adj[u];
    b->vertex = u; b->capacity = w; b->flow = 0; b->next = g->adj[v];
    a->rev = b; b->rev = a;
    g->adj[u] = a;
    g->adj[v] = b;

    edges_u[edge_id] = u;
    edges_v[edge_id] = v;
    edges_c[edge_id++] = w;
}

int dfs(Graph* g, int u, int t, int min_cap) {
    if (u == t) return min_cap;
    visited_dfs[u] = 1;
    for (Node* curr = g->adj[u]; curr; curr = curr->next) {
        int v = curr->vertex;
        if (!visited_dfs[v] && curr->flow < curr->capacity) {
            int delta = dfs(g, v, t, (min_cap < curr->capacity - curr->flow) ? min_cap : (curr->capacity - curr->flow));
            if (delta > 0) {
                curr->flow += delta;
                curr->rev->flow -= delta;
                return delta;
            }
        }
    }
    return 0;
}

int maxFlow(Graph* g, int s, int t) {
    int flow = 0;
    while (1) {
        memset(visited_dfs, 0, sizeof(visited_dfs));
        int delta = dfs(g, s, t, INF);
        if (!delta) break;
        flow += delta;
    }
    return flow;
}

void markReachable(Graph* g, int u) {
    visited_cut[u] = 1;
    for (Node* curr = g->adj[u]; curr; curr = curr->next) {
        if (!visited_cut[curr->vertex] && curr->flow < curr->capacity)
            markReachable(g, curr->vertex);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M, S, T;
    scanf("%d %d", &N, &M);
    scanf("%d %d", &S, &T);

    Graph* g = createGraph(N);

    for (int i = 0; i < M; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        addEdge(g, u, v, c);
    }

    int totalFlow = maxFlow(g, S, T);

    memset(visited_cut, 0, sizeof(visited_cut));
    markReachable(g, S);

    printf("%d ", totalFlow);

    int cutCount = 0;
    for (int i = 0; i < edge_id; i++) {
        int u = edges_u[i];
        int v = edges_v[i];
        if (visited_cut[u] && !visited_cut[v]) {
            cutCount++;
        } else if (visited_cut[v] && !visited_cut[u]) {
            cutCount++;
        }
    }
    printf("%d\n", cutCount);

    for (int i = 0; i < edge_id; i++) {
        int u = edges_u[i];
        int v = edges_v[i];
        if (visited_cut[u] && !visited_cut[v]) {
            printf("%d %d\n", u, v);
        } else if (visited_cut[v] && !visited_cut[u]) {
            printf("%d %d\n", v, u);
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
