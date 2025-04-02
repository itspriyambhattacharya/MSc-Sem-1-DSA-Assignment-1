#include <stdio.h>

#define MAX 10

void initializeMatrix(int a[MAX][MAX], int v){
	int i, j;
	
	for(i = 0 ; i < v; i++){
		for(j = 0; j < v; j++){
			a[i][j] = 0;
		}
	}
}

void addEdge(int a[MAX][MAX], int src, int dest){
	a[src][dest] = 1;
}

void display(int a[MAX][MAX], int v){
	int i, j;
	
	for(i=0; i < v; i++){
		for(int j = 0 ; j < v; j++){
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	int adjM[MAX][MAX]; // adjacency matrix
	int vertices; // number of vertices
	int edges; // number of edges
	int i,j; // loop variables
	
	printf("\nEnter number of vertices and edges present in the graph\n");
	scanf("%d%d", &vertices, &edges);
	initializeMatrix(adjM, vertices);
	
	for(i=0; i < edges; i++){
		int src;
		int dest;
		
		printf("\nEdge %d: Enter source and destination\n", i+1);
		scanf("%d%d", &src, &dest);
		if(src < 0 || src > vertices || dest < 0 || dest > vertices){
			printf("\nInvalid edge, enter again\n");
			i--;
			continue;
		}
		addEdge(adjM, src, dest);	
	}
	printf("\nThe adjacency matrix is:\n");
	display(adjM, vertices);
	
	return 0;
}