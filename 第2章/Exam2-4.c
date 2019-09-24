#include <stdio.h>
#define MaxSize  100
typedef int DataType;
#include "SeqList.h"

int ListDataDelete(SeqList *L, DataType x)
{
	int i, j;

	for(i = 0; i < L->size; i++)				/*Ѱ��Ԫ��x*/
		if(x == L->list[i]) break;
//	for(i = 0; i < L->size && x != L->list[i]; i++);
//	i = 0;
//	while(i < L->size && x != L->list[i])
//		i++;

	if(i == L->size) return 0;					/*δѰ�ҵ�Ԫ��x*/
	else										/*Ѱ�ҵ�Ԫ��x*/
	{
		for(j = i; j < L->size; j++)			/*Ԫ������ǰ��*/
			L->list[j] = L->list[j+1];

		L->size--;								/*Ԫ�ظ�����1*/
		return 1;
	}
}

void main(void)
{
	SeqList myList;
	int a[] = {3, 8, 2, 4, 1, 5, 7};
	int i, x;
	
	ListInitiate(&myList);
	for(i = 0; i < 7; i++)
		ListInsert(&myList, i, a[i]);

	ListDataDelete(&myList, 5);
	for(i = 0; i < ListLength(myList); i++)
	{
		ListGet(myList, i, &x);
		printf("%d   ", x);
	}	
}
