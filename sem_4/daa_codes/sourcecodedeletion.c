#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph node
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent a graph
struct Graph {
    int numVertices;
    struct Node** adjList;
    int* inDegree;
};

// Function to create a new graph node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjList = (struct Node**)malloc(numVertices * sizeof(struct Node*));
    graph->inDegree = (int*)malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; ++i) {
        graph->adjList[i] = NULL;
        graph->inDegree[i] = 0;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    graph->inDegree[dest]++;
}

// Function to perform topological sorting using source code deletion
void topologicalSort(struct Graph* graph) {
    int* result = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    // Enqueue vertices with in-degree zero
    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->inDegree[i] == 0) {
            result[rear++] = i;
        }
    }

    // Source code deletion
    while (front < rear) {
        int currentVertex = result[front++];
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjList[currentVertex];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            graph->inDegree[neighbor]--;
            
            if (graph->inDegree[neighbor] == 0) {
                result[rear++] = neighbor;
            }

            temp = temp->next;
        }
    }

    free(result);
}

// Driver program
int main() {
    int numVertices = 6;
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    printf("Topological Sorting: ");
    topologicalSort(graph);

    free(graph);

    return 0;
}
