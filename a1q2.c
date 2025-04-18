#include <stdio.h>
#define MAX 10

int dOrUd= 0;
int isWeighted = 0;

void initializeMatrix(int a[MAX][MAX], int v, int e){
	int i, j; // loop variables
	
	for(i=0;i< v; i++){
		for(j= 0 ; j< e; j++){
			a[i][j] = 0;
		}
	}
}

void addEdge(int a[MAX][MAX], int src, int dest, int edgeCount){
	if(dOrUd == 2 && isWeighted == 2){
		a[src][edgeCount] = 1;
		a[dest][edgeCount] = 1;
	}
	else if (dOrUd == 2 && isWeighted == 1){
		int wt;
		printf("\nEnter weight:\t");
		scanf("%d", &wt);
		a[src][edgeCount] = wt;
		a[dest][edgeCount] = wt;
	}
	else if(dOrUd == 1 && isWeighted == 2){
		a[src][edgeCount] = 1;
		a[dest][edgeCount] = -1;
	}
	else if (dOrUd == 1 && isWeighted == 1){
		int wt;
		printf("\nEnter weight:\t");
		scanf("%d", &wt);
		a[src][edgeCount] = wt;
		a[dest][edgeCount] = -wt;
	}
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
	printf("\nEnter \'1\' for directed and \'2\' for undirected:\t");
	scanf("%d",&dOrUd);
	
	printf("\nEnter \'1\' for weighted and \'2\' for unweighted:\t");
	scanf("%d",&isWeighted);
	
	printf("\nEnter number of vertices and edges respectively\n");
	scanf("%d%d", &vertices, &edges);
	
	initializeMatrix(adjM, vertices, edges);
	
	for(i=0; i< edges; i++){
		int src;
		int dest;
		printf("\nEnter source and destination respectively of edge %d\n", i+1);
		scanf("%d%d", &src, &dest);
		
		if(src< 0 || src>= vertices || dest < 0|| dest >= vertices){
			printf("\nInvalid Input\n");
			i--;
			continue;
		}
		addEdge(adjM, src, dest, i);
	}
	display(adjM, vertices, edges);
	return 0;
}