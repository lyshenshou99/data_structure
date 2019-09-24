#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char DataType;
#define MaxVertices 100
#include "AdjLGraph.h"

typedef struct
{
	int row;
	int col;
} RowCol;

void CreatGraph(AdjLGraph *G, DataType v[], int n, RowCol d[], int e)
{
	int i, k;

	AdjInitiate(G);
	for(i = 0; i < n; i++) InsertVertex(G, i, v[i]);
	for(k = 0; k < e; k++) InsertEdge(G, d[k].row, d[k].col);
}

void main(void)
{
	AdjLGraph g;

	char a[] = {'A','B','C','D','E'};
	RowCol rc[] = {{0,1},{1,3},{3,2},{2,1},{0,4}};
	int i, n = 5, e = 5;

	Edge *p;
	CreatGraph(&g, a, n, rc, e);

	printf("%d   %d\n", g.numOfVerts, g.numOfEdges);
	for(i = 0; i < g.numOfVerts; i++)
	{
		printf("%c   ", g.a[i].data);
		p = g.a[i].adj;
		while(p != NULL) 
		{
			printf("%d   ", p->dest);
			p = p->next;
		}
		printf("\n");
	}
DeleteEdge(&g, 1, 3);

	printf("%d   %d\n", g.numOfVerts, g.numOfEdges);
	for(i = 0; i < g.numOfVerts; i++)
	{
		printf("%c   ", g.a[i].data);
		p = g.a[i].adj;
		while(p != NULL) 
		{
			printf("%d   ", p->dest);
			p = p->next;
		}
		printf("\n");
	}

	AdjDestroy(&g);
}
