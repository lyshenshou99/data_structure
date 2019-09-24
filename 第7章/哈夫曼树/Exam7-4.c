#include <stdio.h>
#include <stdlib.h>

#define MaxValue 10000				/*初始设定的权值最大值*/
#define MaxBit 10					/*初始设定的最大编码位数*/
#define MaxN 10						/*初始设定的最大结点个数*/

#include "Haffman.h"

void main(void)
{
	int i, j, n = 4;
	int weight[] = {1,3,5,7};

	HaffNode *myHaffTree = (HaffNode *)malloc(sizeof(HaffNode)*(2*n+1));
	Code *myHaffCode = (Code *)malloc(sizeof(Code)*n);

	if(n > MaxN)
	{
		printf("给出的n越界，修改MaxN!\n");
		exit(1);
	}
	Haffman(weight, n, myHaffTree);
	HaffmanCode(myHaffTree, n, myHaffCode);

	/*输出每个叶结点的哈夫曼编码*/
	for(i = 0; i < n; i++)
	{
		printf("Weight = %d   Code = ", myHaffCode[i].weight);
		for(j = myHaffCode[i].start; j < n; j++)
			printf("%d", myHaffCode[i].bit[j]);
		printf("\n");
	}
}
