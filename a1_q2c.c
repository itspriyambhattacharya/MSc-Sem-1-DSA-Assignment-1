#include <stdio.h>
#define MAX 10

void initializeMatrix(int a[MAX][MAX], int v, int e){
	int i, j; // loop variables
	
	for(i=0;i< v; i++){
		for(j= 0 ; j< e; j++){
			a[i][j] = 0;
		}
	}
}

void addEdge(int a[MAX][MAX], int src, int dest, int edgeCount){
	a[src][edgeCount] = 1;
}

void display(int a[MAX][MAX], int v, int e){
	int i, j; // loop variables
	
	for(i=0;i< v; i++){
		for(j= 0 ; j< e; j++){
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	int adjM[MAX][MAX];
	int edges; // total number of edges present in graph
	int vertices; // total number of vertices present in graph
	int i, j;
	printf("\nEnter number of vertices and edges respectively\n");
	scanf("%d%d", &vertices, &edges);
	
	initializeMatrix(adjM, vertices, edges);
	
	for(i=0; i< edges; i++){
		int src;
		int dest;
		printf("\nEnter source and destination respectively of edge %d\n", i+1);
		scanf("%d%d", &src, &dest);
		
		if(src< 0 || src> vertices || dest < 0|| dest > vertices){
			printf("\nInvalid Input\n");
			i--;
			continue;
		}
		addEdge(adjM, src, dest, i);
	}
	printf("\nThe incidence matrix is:\n");
	display(adjM, vertices, edges);
	return 0;
}