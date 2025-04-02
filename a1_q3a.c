#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct Link{
	Node *head;
}Link;

void initializeList(Link* adjL, int v){
	int i;
	
	for(i=0; i< v; i++){
		adjL[i].head = NULL;
	}
}

int addEdgeBeginning(Link* adjL, int src, int dest){
	Node *srcNode = (Node *) malloc(sizeof(Node));
	Node *destNode = (Node *)malloc(sizeof(Node));
	
	if(!srcNode || !destNode){
		printf("\n Memory allocation failed.");
		return -1;
	}
	
	srcNode->data = dest;
	srcNode->next = adjL[src].head;
	adjL[src].head = srcNode;
	
	destNode->data = src;
	destNode->next = adjL[dest].head;
	adjL[dest].head = destNode;
	return 1;
}

int addEdgeEnd(Link *adjL, int src, int dest, int v){
	int i;
	Node *srcNode = (Node *) malloc(sizeof(Node));
	Node *destNode = (Node *)malloc(sizeof(Node));
	
	if(!srcNode || !destNode){
		printf("\n Memory allocation failed.");
		return -1;
	}
	srcNode->data = dest;
	srcNode->next = NULL;
	
	destNode->data = src;
	destNode->next = NULL;
	
	for(i=0; i< v; i++){
		if(i == src){
			if(adjL[i].head != NULL){
				Node *ptr = adjL[i].head;
				while(ptr->next != NULL){
					ptr = ptr->next;
				}
				ptr->next = srcNode;
			}
			else{
				adjL[i].head = srcNode;
			}
		}
	}
	
	for(i=0; i< v; i++){
		if(i == dest){
			if(adjL[i].head != NULL){
				Node *ptr = adjL[i].head;
				while(ptr->next != NULL){
					ptr = ptr->next;
				}
				ptr->next = destNode;
			}
			else{
				adjL[i].head = destNode;
			}
		}
	}
	return 1;
}

void display(Link * adjL, int v){
	int i;
	for(i = 0; i < v; i++){
		Node *ptr = adjL[i].head;
		printf("\n Vertex %d:\t", i);
		while(ptr != NULL){
			printf("%d ---> ", ptr->data);
			ptr = ptr->next;
		}
		printf("NULL\n");
	}
}

int main(void){
	int vertices; // total number of vertices present in graph
	int edges; // total number of edges present in graph
	int i,j; // loop variables
	int memAlloc;
	
	printf("\n Enter number of vertices present in graph:\t");
	scanf("%d", &vertices);
	printf("\n Enter number of edges present in the graph:\t");
	scanf("%d", &edges);
	
	Link *adjL = (Link *) malloc(vertices * sizeof(Link));
	initializeList(adjL, vertices); // initializing the adjacency list
	
	// enter source and destination vertices where edges are present in graph
	
	for(i = 0; i < edges; i++){
		int src; // source vertex
		int dest; // destination vertex
		printf("\n Enter source vertex:\t");
		scanf("%d", &src);
		printf("\n Enter destination vertex:\t");
		scanf("%d", &dest);
		memAlloc = addEdgeEnd(adjL, src, dest, vertices);
		if(memAlloc != 1){
			exit(1);
		}
	}
	
	printf("\n The adjacency list is:\n");
	display(adjL, vertices);
	
	free(adjL);
	return 0;
}