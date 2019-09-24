#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef int DataType;
#include "SeqList.h"
void Converse(SeqList *L)
{
	int mid, i;
	DataType x;
	mid = L->size / 2;
	for(i = 0; i < mid; i++)
	{
		x = L->list[i];
		L->list[i] = L->list[L->size - 1 - i];
		L->list[L->size - 1 - i] = x;
	}
}

void main(void)
{
	SeqList myList;
	int i, a[] = {1,2,3,4,5,6,7,8,9,10};
	DataType x;

	ListInitiate(&myList);
	for(i = 0; i < 10; i++)
	{
		if(ListInsert(&myList, i, a[i]) == 0) 
		{
			printf("´íÎó! \n");
			exit(1);
		}
	}
	Converse(&myList);
	for(i = 0; i < myList.size; i++)
	{
		if(ListGet(myList, i, &x) == 0) 
		{
			printf("´íÎó! \n");
			exit(1);
		}
		else printf("%d  ", x);
	}	
}