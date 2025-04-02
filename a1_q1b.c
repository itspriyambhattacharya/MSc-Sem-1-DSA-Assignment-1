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

void addEdge(int a[MAX][MAX], int src, int dest, int wt){
	a[src][dest] = wt;
	a[dest][src] = wt;
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
		int wt;
		
		printf("\nEdge %d: Enter source and destination and weight of the edge\n", i+1);
		scanf("%d%d%d", &src, &dest, &wt);
		if(src < 0 || src > vertices || dest < 0 || dest > vertices){
			printf("\nInvalid edge, enter again\n");
			i--;
			continue;
		}
		addEdge(adjM, src, dest, wt);	
	}
	printf("\nThe adjacency matrix is:\n");
	display(adjM, vertices);
	
	return 0;
}