#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    int weight;
    int flight_num; 
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

void addNode(Graph* g, int u, int v, int weight, int flight_num) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->flight_num = flight_num;
    newNode->next = g->adj[u];
    g->adj[u] = newNode;
}

void bellmanford(Graph* g, int start, int end, int *dist, int *prev, int *flight_used) {
    int V = g->V;

    for (int i = 0; i <= V; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
        flight_used[i] = -1;
    }
    dist[start] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int u = 1; u <= V; u++) {
            if (dist[u] == INT_MAX) continue;
            
            for (Node* node = g->adj[u]; node != NULL; node = node->next) {
                int v = node->vertex;
                int weight = node->weight;
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    flight_used[v] = node->flight_num;
                }
            }
        }
    }
}

void reconstructPath(int end, int *prev, int *flight_used, int *path, int *path_length) {
    *path_length = 0;
    int current = end;
    int temp_path[1000000]; 
    int temp_length = 0;

    while (prev[current] != -1) {
        temp_path[temp_length++] = flight_used[current];
        current = prev[current];
    }

    
    for (int i = temp_length - 1; i >= 0; i--) {
        path[(*path_length)++] = temp_path[i];
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    Graph *g = createGraph(N);
    int requests[20][2];  

    for(int i = 0; i < K; i++){
        scanf("%d %d", &requests[i][0], &requests[i][1]);
    }

    for(int i = 0; i < M; i++){
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        addNode(g, from, to, weight, i + 1);  
    }

    int *dist = (int*)malloc((N + 1) * sizeof(int));
    int *prev = (int*)malloc((N + 1) * sizeof(int));
    int *flight_used = (int*)malloc((N + 1) * sizeof(int));
    int path[1000000];
    int path_length;

    for(int i = 0; i < K; i++){
        int start = requests[i][0];
        int end = requests[i][1];
        
        bellmanford(g, start, end, dist, prev, flight_used);
        
        if(dist[end] == INT_MAX){
            printf("DOOMED\n");
        } else {
            reconstructPath(end, prev, flight_used, path, &path_length);
            printf("quarantine %d %d", dist[end], path_length);
            for(int j = 0; j < path_length; j++){
                printf(" %d", path[j]);
            }
            printf("\n");
        }
    }


    for (int i = 0; i <= N; i++) {
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
    free(prev);
    free(flight_used);

    fclose(stdin);
    fclose(stdout);
    return 0;
}