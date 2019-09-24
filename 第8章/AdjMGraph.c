#include <stdio.h>
#include <stdlib.h>

typedef char DataType;		
#define MaxSize 100
#define MaxVertices 10
#define MaxEdges 100
#define MaxWeight 10000

#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"

void main(void)
{
	AdjMWGraph g1;
	DataType a[] = {'A','B','C','D','E'};
	RowColWeight rcw[] = {{0,1,10},{0,4,20},{1,3,30},{2,1,40},{3,2,50}};
	int n = 5, e = 5;
	int i, j;

	CreatGraph(&g1, a, n, rcw, e);
	DeleteEdge(&g1, 0, 4);					/*删除边<0, 4>*/
	DeleteVertex(&g1, 3);					/*删除顶点3*/

	printf("顶点集合为：");
	for(i = 0; i < g1.Vertices.size; i++)
		printf("%c   ", g1.Vertices.list[i]);
	printf("\n");

	printf("权值集合为：\n");
	for(i = 0; i < g1.Vertices.size; i++)
	{
		for(j = 0; j < g1.Vertices.size; j++)
			printf("%5d   ", g1.edge[i][j]);
		printf("\n");
	}
}
