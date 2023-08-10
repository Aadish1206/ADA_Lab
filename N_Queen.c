#include <stdio.h>
#include <stdbool.h>
#include <limits.h> // Include this header for INT_MAX constant

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;

void primMST() {
    int parent[MAX_VERTICES]; // Array to store the MST
    int key[MAX_VERTICES];    // Key values used to pick minimum weight edge

    bool mstSet[MAX_VERTICES]; // To keep track of vertices included in MST
    for (int i = 0; i < numVertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;       // Start with the first vertex
    parent[0] = -1;   // First node is always the root of MST

    for (int count = 0; count < numVertices - 1; count++) {
        int u = -1;
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        for (int v = 0; v < numVertices; v++) {
            if (!mstSet[v] && (u == -1 || key[v] < key[u]))
                u = v;
        }

        mstSet[u] = true; // Include the picked vertex in MST

        // Update key values and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < numVertices; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (int i = 1; i < numVertices; i++) {
        printf("%d - %d\n", parent[i], i);
    }
}

int main() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST();

    return 0;
}
