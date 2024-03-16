#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Stack implementation
typedef struct {
    int items[MAX_NODES];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

void push(Stack *s, int value) {
    if (s->top == MAX_NODES - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Graph representation
typedef struct {
    int numVertices;
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
} Graph;

void initGraph(Graph *graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    // For undirected graphs, uncomment the following line
    // graph->adjacencyMatrix[dest][src] = 1;
}

// Depth-First Search function
void DFS(Graph *graph, int startVertex) {
    Stack stack;
    initStack(&stack);

    int visited[MAX_NODES] = {0};
    push(&stack, startVertex);

    while (!isEmpty(&stack)) {
        int currentVertex = pop(&stack);

        if (!visited[currentVertex]) {
            printf("Push: %d\n", currentVertex);
            visited[currentVertex] = 1;

            // Push neighbors onto the stack
            for (int i = graph->numVertices - 1; i >= 0; i--) {
                if (graph->adjacencyMatrix[currentVertex][i] && !visited[i]) {
                    push(&stack, i);
                }
            }

            printf("Pop: %d\n", currentVertex);
        }
    }
}

int main() {
    Graph graph;
    int numVertices, numEdges;
    int src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    initGraph(&graph, numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    printf("DFS Traversal:\n");
    DFS(&graph, 0); // Starting DFS from vertex 0

    return 0;
}
