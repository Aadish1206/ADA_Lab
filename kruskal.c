#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // Include this header for qsort function

#define MAX_EDGES 100
#define MAX_VERTICES 100

typedef struct {
    int src, dest, weight;
} Edge;

int parent[MAX_VERTICES];
Edge edges[MAX_EDGES];
int numVertices, numEdges;

void makeSet(int v) {
    parent[v] = v;
}

int findSet(int v) {
    if (parent[v] != v)
        parent[v] = findSet(parent[v]);
    return parent[v];
}

void unionSets(int v1, int v2) {
    int root1 = findSet(v1);
    int root2 = findSet(v2);
    parent[root2] = root1;
}

int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void kruskalMST() {
    for (int i = 0; i < numVertices; i++) {
        makeSet(i);
    }

    qsort(edges, numEdges, sizeof(Edge), compareEdges);

    printf("Minimum Spanning Tree:\n");
    int mstWeight = 0;
    for (int i = 0; i < numEdges; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;

        if (findSet(src) != findSet(dest)) {
            printf("%d - %d\n", src, dest);
            mstWeight += weight;
            unionSets(src, dest);
        }
    }

    printf("Minimum Spanning Tree Weight: %d\n", mstWeight);
}

int main() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    printf("Enter the edges in the format [source] [destination] [weight]:\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskalMST();

    return 0;
}
