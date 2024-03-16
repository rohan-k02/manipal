#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Queue implementation
typedef struct {
    int items[MAX_NODES];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return (q->rear == -1);
}

int isFull(Queue *q) {
    return (q->rear == MAX_NODES - 1);
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return item;
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

// Breadth-First Search function
void BFS(Graph *graph, int startVertex) {
    Queue queue;
    initQueue(&queue);

    int visited[MAX_NODES] = {0};
    enqueue(&queue, startVertex);
    visited[startVertex] = 1;

    while (!isEmpty(&queue)) {
        int currentVertex = dequeue(&queue);
        printf("Visited: %d\n", currentVertex);

        // Enqueue all unvisited neighbors
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] && !visited[i]) {
                enqueue(&queue, i);
                visited[i] = 1;
            }
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

    printf("BFS Traversal:\n");
    BFS(&graph, 0); // Starting BFS from vertex 0

    return 0;
}
