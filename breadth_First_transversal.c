#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 26

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

void breadthFirstTraversal(int startNode, int numNodes) {
    int queue[MAX_NODES];
    int front = 0, rear = -1;
  
    visited[startNode] = 1;
    printf("%c ", startNode + 'A');
    queue[++rear] = startNode;
  
    while (front <= rear) {
        int currentNode = queue[front++];
  
        for (int i = 0; i < numNodes; i++) {
            if (graph[currentNode][i] && !visited[i]) {
                visited[i] = 1;
                printf("%c ", i + 'A');
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int numNodes;
    char nodes[MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);


    printf("Enter the labels for each node :\n");
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

    printf("Breadth First Traversal Order: ");
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            breadthFirstTraversal(i, numNodes);
        }
    }
    printf("\n");

    return 0;
}
