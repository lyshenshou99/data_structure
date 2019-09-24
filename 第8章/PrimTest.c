#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char DataType;		
typedef char VerT;		
#define MaxSize 100
#define MaxVertices 10
#define MaxWeight 10000
#define N 7

#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"
#include "Prim.h"

void main(void)
{
	AdjMWGraph g;
	char a[] = {'A','B','C','D','E','F','G'};
	RowColWeight rcw[] = {{0,1,50},{1,0,50},{0,2,66},{2,0,60},{1,3,65},{3,1,65},
		{1,4,40},{4,1,40},{2,3,52},{3,2,52},{2,6,45},{6,2,45},{3,4,50},{4,3,50},
		{3,5,30,},{5,3,30},{3,6,42},{6,3,42},{4,5,70},{5,4,70}};
	int n = 7, e = 20, i;
	MinSpanTree closeVertex[7];

	CreatGraph(&g, a, n, rcw, e);
	Prim(g, closeVertex);

	//输出Prim函数得到的最小生成树的顶点序列和权值序列
	printf("初始顶点 = %c\n", closeVertex[0].vertex);
	for(i = 1; i < n; i++)
		printf("顶点 = %c  边的权值 = %d\n", closeVertex[i].vertex, closeVertex[i].weight);
}
