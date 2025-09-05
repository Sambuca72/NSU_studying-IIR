#include "sol.h"
#include <stdlib.h>

#define MAX_N 630000  
#define INIT_CAP 4    

typedef struct {
    Edge* edges;     
    int count;       
    int capacity;     
} EdgeList;

static int vertexCount;
static EdgeList* incidentLists = NULL;

void addEdgeToVertex(int vertex, Edge edge) {
    EdgeList* list = &incidentLists[vertex];
    if (list->count == list->capacity) {
        list->capacity = list->capacity == 0 ? INIT_CAP : list->capacity * 2;
        list->edges = (Edge*)realloc(list->edges, list->capacity * sizeof(Edge));
    }
    list->edges[list->count++] = edge;
}

void init() {
    vertexCount = getVerticesCount();
    incidentLists = (EdgeList*)calloc(vertexCount, sizeof(EdgeList));

    Edge e;
    while (readEdge(&e)) {
        Edge ef = e;
        ef.from = e.from;
        ef.to = e.to;
        addEdgeToVertex(e.from, ef);


        Edge et = e;
        et.from = e.to;
        et.to = e.from;
        addEdgeToVertex(e.to, et);

       
    }
}

int getEdgesCount(int iVertex) {
    return incidentLists[iVertex].count;
}

Edge getIncidentEdge(int iVertex, int iIndex) {
    return incidentLists[iVertex].edges[iIndex];
}
