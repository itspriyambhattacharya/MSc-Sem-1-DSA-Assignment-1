#include <stdio.h>

#define MAX 10

int dOrUd;
int isWeighted;

void initializeMatrix(int a[MAX][MAX], int v)
{
	int i, j;

	for (i = 0; i < v; i++)
	{
		for (j = 0; j < v; j++)
		{
			a[i][j] = 0;
		}
	}
}

void addEdge(int a[MAX][MAX], int src, int dest)
{
	if(dOrUd == 2 && isWeighted == 2){
		a[src][dest] = 1;
		a[dest][src] = 1;
	}
	else if(dOrUd == 2 && isWeighted == 1){
		int wt;
		printf("\nEnter edge weight:\t");
		scanf("%d", &wt);
		a[src][dest] = wt;
		a[dest][src] = wt;
	}
	else if(dOrUd == 1 && isWeighted == 2){
		a[src][dest] = 1;
	}
	else if(dOrUd == 1 && isWeighted == 1){
		int wt;
		printf("\nEnter edge weight:\t");
		scanf("%d", &wt);
		a[src][dest] = wt;
	}
}

void display(int a[MAX][MAX], int v)
{
	int i, j;

	for (i = 0; i < v; i++)
	{
		for (j = 0; j < v; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int adjM[MAX][MAX]; // adjacency matrix
	int vertices;		// number of vertices
	int edges;			// number of edges
	int i, j;			// loop variables
	
	printf("\nIs the graph directed or undirected? Press \'1\' for directed and \'2\' for undirected:\t");
	scanf("%d", &dOrUd);
	
	printf("\nIs the graph weighted or unweighted? Press \'1\' for weighted and \'2\' for unweighted:\t");
	scanf("%d", &isWeighted);

	printf("\nEnter number of vertices and edges present in the graph\n");
	scanf("%d%d", &vertices, &edges);
	initializeMatrix(adjM, vertices);

	for (i = 0; i < edges; i++)
	{
		int src;
		int dest;

		printf("\nEdge %d: Enter source and destination vertex\n", i + 1);
		scanf("%d%d", &src, &dest);
		if (src < 0 || src > vertices || dest < 0 || dest > vertices)
		{
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