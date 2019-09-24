#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char DataType;		
#define MaxSize 100
#define MaxVertices 10
#define MaxEdges 100
#define MaxWeight 10000
#define MaxQueueSize 100

#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"
#include "AdjMGraphTraverse.h"

void Visit(DataType item)
{
	printf("%c   ", item);
}

void main(void)
{
	AdjMWGraph g1;
	DataType a[] = {'A','B','C','D','E'};
	RowColWeight rcw[] = {{0,1,10},{0,4,20},{1,3,30},{2,1,40},{3,2,50}};
	int n = 5, e = 5;

	CreatGraph(&g1, a, n, rcw, e);

	printf("深度优先搜索序列为：");
	DepthFirstSearch(g1);

	printf("\n广度优先搜索序列为：");
	BroadFirstSearch(g1);
}
