#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 15

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

void depthFirstTraversal(int node) {
    visited[node] = 1;
    printf("%c ", node + 'A');

    for (int i = 0; i < MAX_NODES; i++) {
        if (graph[node][i] && !visited[i]) {
            depthFirstTraversal(i);
        }
    }
}

int main() {
    int numNodes;
    char nodes[MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the labels for each node:\n");
    for (int i = 0; i < numNodes; i++) {
        scanf(" %c", &nodes[i]);
    }

    printf("Enter the adjacency matrix :\n");
    for (int i = 0; i < numNodes; i++) {
        visited[i] = 0;
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Depth First Traversal Order: ");
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            depthFirstTraversal(i);
        }
    }
    printf("\n");

    return 0;
}
