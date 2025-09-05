#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int N;

//почему форд фокус
/*прост в реализации, но нестабилен. Аналоги: Эдмондс-Карп(работает за VE^2)стабильнее, но сложнее в реализации. 
Алгоритм диница  сложнее, но стабильнее, он строит уровневый граф через BFS потом DFS*/

typedef struct Node {
    int vertex;
    int capacity;
    int flow;
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

void addNode(Graph* g, int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->capacity = w;
    newNode->flow = 0;
    newNode->next = g->adj[u];
    g->adj[u] = newNode;

    Node* revNode = (Node*)malloc(sizeof(Node));
    revNode->vertex = u;
    revNode->capacity = 0; 
    revNode->flow = 0;
    revNode->next = g->adj[v];
    g->adj[v] = revNode;
}

int min(int a, int b){
    return((a < b) ? a : b);
}

int ford_focus(Graph* g, int u, int t, int min_cap, int* visited) {
    if (u == t) return min_cap;

    visited[u] = 1;

    Node* curr = g->adj[u];
    while (curr) {
        int v = curr->vertex;
        int c = curr->capacity;
        int f = curr->flow;

        if (!visited[v] && f < c) {
            int delta = ford_focus(g, v, t, min(min_cap, c - f), visited);
            if (delta > 0) {
               
                curr->flow += delta;

                Node* rev = g->adj[v];
                while (rev) {
                    if (rev->vertex == u) {
                        rev->flow -= delta;
                        break;
                    }
                    rev = rev->next;
                }

                return delta;
            }
        }
        curr = curr->next;
    }
    return 0;
}


int maxFlow(Graph* g, int s, int t) {
    int flow = 0;
    int* visited = (int*)calloc((g->V + 1), sizeof(int));

    while (1) {
        memset(visited, 0, (g->V + 1) * sizeof(int));
        int delta = ford_focus(g, s, t, 1e9, visited);
        if (delta == 0)
            break;
        flow += delta;
    }


    free(visited);
    return flow;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int K;
    scanf("%d %d", &N, &K);

    Graph *g = createGraph(N);

    for(int i = 0; i < K; i++){
        int u, v, w;
        scanf("%d %d %d", &v, &u, &w);
        addNode(g, u, v, w);
        addNode(g, v, u, w);   
    }

    int maxflow = maxFlow(g, 1, N);

    printf("%d", maxflow);

    fclose(stdin);
    fclose(stdout);
}