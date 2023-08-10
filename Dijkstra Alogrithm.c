#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 100
#define INF 9999

int graph[MAX_NODES][MAX_NODES];

void dijkstra(int numNodes, int startNode) {
    int distance[numNodes];
    bool visited[numNodes];

    for (int i = 0; i < numNodes; i++) {
        distance[i] = INF;
        visited[i] = false;
    }

    distance[startNode] = 0;

    for (int i = 0; i < numNodes - 1; i++) {
        int minDistance = INF;
        int minIndex = -1;

        for (int j = 0; j < numNodes; j++) {
            if (!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                minIndex = j;
            }
        }

        if (minIndex == -1)
            break;

        visited[minIndex] = true;

        for (int j = 0; j < numNodes; j++) {
            if (!visited[j] && graph[minIndex][j] && distance[minIndex] != INF &&
                distance[minIndex] + graph[minIndex][j] < distance[j]) {
                distance[j] = distance[minIndex] + graph[minIndex][j];
            }
        }
    }

    printf("Shortest distances from node %d:\n", startNode);
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d: %d\n", i, distance[i]);
    }
}

int main() {
    int numNodes, numEdges;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges and their weights:\n");
    for (int i = 0; i < numEdges; i++) {
        int node1, node2, weight;
        scanf("%d %d %d", &node1, &node2, &weight);
        graph[node1][node2] = weight;
        graph[node2][node1] = weight;
    }

    int startNode;
    printf("Enter the starting node: ");
    scanf("%d", &startNode);

    dijkstra(numNodes, startNode);

    return 0;
}
