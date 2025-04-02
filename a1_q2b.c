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

void addEdge(int a[MAX][MAX], int src, int dest, int edgeCount, int wt){
	a[src][edgeCount] = wt;
	a[dest][edgeCount] = wt;
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
		int wt;
		printf("\nEnter source, destination and weight respectively of edge %d\n", i+1);
		scanf("%d%d%d", &src, &dest, &wt);
		
		if(src< 0 || src> vertices || dest < 0|| dest > vertices){
			printf("\nInvalid Input\n");
			i--;
			continue;
		}
		addEdge(adjM, src, dest, i, wt);
	}
	display(adjM, vertices, edges);
	return 0;
}