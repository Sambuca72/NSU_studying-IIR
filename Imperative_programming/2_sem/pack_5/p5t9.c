#include <stdio.h>
#include <stdlib.h>

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

void addNode(Graph* g, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v - 1;
    newNode->next = g->adj[u - 1];
    g->adj[u - 1] = newNode;
}

int DFS(Graph *g, int u, int *order, int *order_idx, int *visited ,int t, int *component, int comp_num){
    visited[u] = 1;
    if(t){
        component[u] = comp_num;
    }
    Node* node = g->adj[u];
    while (node)
    {
        int v = node->vertex;
        if(!visited[v]){
            DFS(g, v, order, order_idx, visited, t, component, comp_num);
        }
        node = node->next;
    }
    if(!t){
        order[(*order_idx)++] = u;   
    } 
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M;
    scanf("%d %d", &N, &M);

    Graph *g = createGraph(N);
    Graph *invG = createGraph(N);

    for(int i = 0; i < M; i++){
        int from, where;
        scanf("%d %d", &from, &where);
        addNode(g, from, where);
        addNode(invG, where, from);
    }

    int *order = (int*)calloc(N,sizeof(int));
    int *visited = (int*)calloc(N,sizeof(int));
    int *component = (int*)malloc(N * sizeof(int));
    int component_size = 0;
    int order_idx = 0;
    int t = 0;
    int comp_num = 0;

    for(int i = 0; i < g->V; i++){
        if(!visited[i]){
            DFS(g, i, order, &order_idx, visited, t, component, comp_num);
        }
    }

    visited = (int*)calloc(N, sizeof(int));
    t = 1;
    
    for(int i = order_idx - 1; i >= 0; i--){
        int u = order[i];
        if(!visited[u]){
            comp_num++;
            component_size = 0;
            DFS(invG, u, order, &order_idx, visited, t, component, comp_num);
        }
    }
    
    printf("%d\n", comp_num);

    for(int u = 0; u < g->V; u++){
        printf("%d ", component[u]);
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

    free(visited);
    free(order);
    free(component);

    fclose(stdin);
    fclose(stdout);
}
