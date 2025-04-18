#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int dOrUd;
int isWeighted;

// Structure for a node in the adjacency list
typedef struct Node {
    int dest;
    int weight;
    struct Node* next;
} Node;

// Adjacency list is an array of node pointers
Node* adjList[MAX];

// Function to create a new node
Node* createNode(int dest, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Initialize adjacency list
void initializeGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
    }
}

// Add edge to the graph
void addEdge(int src, int dest) {
    int weight = 1;

    if (isWeighted == 1) {
        printf("Enter edge weight from %d to %d: ", src, dest);
        scanf("%d", &weight);
    }

    // Add edge from src to dest
    Node* newNode = createNode(dest, weight);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // If undirected, add edge from dest to src as well
    if (dOrUd == 2) {
        Node* newNode2 = createNode(src, weight);
        newNode2->next = adjList[dest];
        adjList[dest] = newNode2;
    }
}

// Display the adjacency list
void displayGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        Node* temp = adjList[i];
        printf("Vertex %d:", i);
        while (temp != NULL) {
            if (isWeighted == 1)
                printf(" -> %d(wt:%d)", temp->dest, temp->weight);
            else
                printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Free the memory used by the adjacency list
void freeGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        Node* temp = adjList[i];
        while (temp != NULL) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
}

int main() {
    int vertices, edges;

    printf("\nIs the graph directed or undirected? Press '1' for directed and '2' for undirected: ");
    scanf("%d", &dOrUd);

    printf("\nIs the graph weighted or unweighted? Press '1' for weighted and '2' for unweighted: ");
    scanf("%d", &isWeighted);

    printf("\nEnter number of vertices and edges: ");
    scanf("%d%d", &vertices, &edges);

    initializeGraph(vertices);

    for (int i = 0; i < edges; i++) {
        int src, dest;

        printf("\nEdge %d: Enter source and destination vertex: ", i + 1);
        scanf("%d%d", &src, &dest);

        if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
            printf("Invalid edge, enter again\n");
            i--;
            continue;
        }

        addEdge(src, dest);
    }

    printf("\nThe adjacency list representation is:\n");
    displayGraph(vertices);

    freeGraph(vertices);
    return 0;
}
