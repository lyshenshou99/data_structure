#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char DataType;		
#define MaxSize 100
#define MaxVertices 10
#define MaxWeight 9999
#define N 3

#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"

void Floyd(int cost[][N], int n, int weight[][N], int path[][N])
{
	int i, j, k;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
		{
			weight[i][j] = cost[i][j];
			path[i][j] = -1;
		}

	for(k = 0; k < n; k++)
	{
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				if(weight[i][j] > weight[i][k] + weight[k][j])
				{
					weight[i][j] = weight[i][k] + weight[k][j];
					path[i][j] = k;
				}
	}

}

void main(void)
{
	int cost[N][N] = {{0,12,5},{4,0,MaxWeight},{MaxWeight,6,0}};
	int weight[N][N], path[N][N], n = 3;
	int i, j;

	Floyd(cost, n, weight, path);

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			printf("%d   ", weight[i][j]);
		printf("\n");
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			printf("%d   ", path[i][j]);
		printf("\n");
	}
}
