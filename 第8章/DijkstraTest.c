#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char DataType;		
#define MaxSize 100
#define MaxVertices 10
#define MaxWeight 10000

#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"
#include "Dijkstra.h"

void main(void)
{
	AdjMWGraph g;
	char a[] = {'A','B','C','D','E','F'};
	RowColWeight rcw[] = {{0,2,5},{0,3,30},{1,0,2},{1,4,8},{2,1,15},{2,5,7},
		{4,3,4},{5,3,10},{5,4,18}};
	int i, n = 6, e = 9;
	int distance[6], path[6];

	CreatGraph(&g, a, n, rcw, e);

	Dijkstra(g, 0, distance, path);

	printf("�Ӷ���%c���������������̾���Ϊ��\n", g.Vertices.list[0]);
	for(i = 0; i < n; i++)
		printf("������%c����̾���Ϊ%d\n", g.Vertices.list[i], distance[i]);

	printf("�Ӷ���%c���������������·����ǰһ����Ϊ��\n", g.Vertices.list[0]);
	for(i = 0; i < n; i++)
		if(path[i] != -1)
			printf("������ %c��ǰһ����Ϊ%c\n", 
				g.Vertices.list[i], g.Vertices.list[path[i]]);
}
