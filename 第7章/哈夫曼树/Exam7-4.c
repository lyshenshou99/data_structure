#include <stdio.h>
#include <stdlib.h>

#define MaxValue 10000				/*��ʼ�趨��Ȩֵ���ֵ*/
#define MaxBit 10					/*��ʼ�趨��������λ��*/
#define MaxN 10						/*��ʼ�趨����������*/

#include "Haffman.h"

void main(void)
{
	int i, j, n = 4;
	int weight[] = {1,3,5,7};

	HaffNode *myHaffTree = (HaffNode *)malloc(sizeof(HaffNode)*(2*n+1));
	Code *myHaffCode = (Code *)malloc(sizeof(Code)*n);

	if(n > MaxN)
	{
		printf("������nԽ�磬�޸�MaxN!\n");
		exit(1);
	}
	Haffman(weight, n, myHaffTree);
	HaffmanCode(myHaffTree, n, myHaffCode);

	/*���ÿ��Ҷ���Ĺ���������*/
	for(i = 0; i < n; i++)
	{
		printf("Weight = %d   Code = ", myHaffCode[i].weight);
		for(j = myHaffCode[i].start; j < n; j++)
			printf("%d", myHaffCode[i].bit[j]);
		printf("\n");
	}
}
