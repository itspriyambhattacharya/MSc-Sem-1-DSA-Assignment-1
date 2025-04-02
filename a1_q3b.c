#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int wt;
    struct Node *next;
} Node;

typedef struct List
{
    Node *link;
} List;

#define MAX 20

void initializeList(List *a, int v)
{
    int i;

    for (i = 0; i < v; i++)
    {
        a[i].link = NULL;
    }
}

void addEdge(List *a, int src, int dest, int wt, int v)
{
    int i;
    Node *srcNode = (Node *)malloc(sizeof(Node));
    Node *destNode = (Node *)malloc(sizeof(Node));

    srcNode->data = dest;
    srcNode->wt = wt;
    srcNode->next = NULL;

    destNode->data = src;
    destNode->wt = wt;
    destNode->next = NULL;

    for (i = 0; i < v; i++)
    {
        if (i == src)
        {
            if (a[i].link != NULL)
            {
                Node *ptr = a[i].link;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = srcNode;
            }
            else
            {
                a[i].link = srcNode;
            }
        }
    }

    for (i = 0; i < v; i++)
    {
        if (i == dest)
        {
            if (a[i].link != NULL)
            {
                Node *ptr = a[i].link;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = destNode;
            }
            else
            {
                a[i].link = destNode;
            }
        }
    }
}

void display(List *a, int v)
{
    int i;

    for (i = 0; i < v; i++)
    {
        Node *ptr = a[i].link;
        printf("\nVertex %d:\t", i);
        while (ptr != NULL)
        {
            printf("%d (%d) ---> ", ptr->data, ptr->wt);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

int main(int argc, char const *argv[])
{
    int vertices;
    int edges;
    int i, j; // loop variables

    printf("\n Enter number of vertices present in graph:\t");
    scanf("%d", &vertices);

    printf("\n Enter number of edges present in graph:\t");
    scanf("%d", &edges);

    List *adjL = (List *)malloc(vertices * sizeof(List));
    initializeList(adjL, vertices);

    for (i = 0; i < edges; i++)
    {
        int src, dest;
        int wt; // weight of the edge
        printf("\nEnter source vertex for edge %d:\t", i + 1);
        scanf("%d", &src);
        printf("\nEnter destination vertex for edge %d:\t", i + 1);
        scanf("%d", &dest);
        printf("\nEnter weight for edge %d:\t", i + 1);
        scanf("%d", &wt);
        addEdge(adjL, src, dest, wt, vertices);
    }
    printf("\nThe adjacency list is:\n");
    display(adjL, vertices);
    free(adjL);
    return 0;
}