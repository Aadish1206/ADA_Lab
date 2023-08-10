#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

// Data structure for stack
struct Stack {
    int arr[MAX_NODES];
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
bool isStackEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int element) {
    stack->arr[++(stack->top)] = element;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    return stack->arr[(stack->top)--];
}

// Recursive function for topological sort
void topologicalSortUtil(int current, bool visited[], int graph[][MAX_NODES], int n, struct Stack* stack) {
    visited[current] = true;

    for (int i = 0; i < n; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            topologicalSortUtil(i, visited, graph, n, stack);
        }
    }

    push(stack, current);
}

// Function to perform topological sort
void topologicalSort(int graph[][MAX_NODES], int n) {
    bool visited[MAX_NODES];
    struct Stack stack;
    initializeStack(&stack);

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, graph, n, &stack);
        }
    }

    printf("Topological Sort Order: ");
    while (!isStackEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
}

int main() {
    int n; // Number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int graph[MAX_NODES][MAX_NODES];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort(graph, n);

    return 0;
}
