#include <stdio.h>

#define INF 999

void floyd(int graph[][100], int V) {
    int dist[V][V];
    int i, j, k;

    // Initialize the distance matrix with the graph values
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Main algorithm loop
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    printf("Shortest distances between all pairs of vertices:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        
    }
}

int main() {
    int V, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[V][100];

    printf("Enter the adjacency matrix (enter 999 for no direct edge):\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == INF)
                graph[i][j] = INF; // Convert any user input as INF to the actual INF value
        }
    }

    floyd(graph, V);

    return 0;
}
