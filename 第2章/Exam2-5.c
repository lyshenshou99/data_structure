#include <stdio.h>
#define MaxSize  100
typedef int DataType;
#include "SeqList.h"

int ListMoreDataDelete(SeqList *L, DataType x)
{
	int i, j;
	int tag = 0;							/*��ʼɾ�������Ϊ0*/

	for(i = 0; i < L->size; i++)			/*Ԫ��x��ȫ��ɾ��*/	
	{
		if(x == L->list[i])					/*Ѱ�ҵ�Ԫ��x*/
		{
			for(j = i; j < L->size; j++)			/*����ǰ��*/
				L->list[j] = L->list[j+1];
			
			L->size--;								/*Ԫ�ظ�����1*/
			i--;			/*��֤�������ٵ�Ԫ�ؾ�Ϊxʱ��ȷɾ��*/
			tag = 1;							/*����ɾ���ɹ����*/
		}
	}

	return tag;
}

void main(void)
{
	SeqList myList;
	int a[] = {3, 8, 2, 1, 5, 5,7};
	int i, x = 5;
	
	ListInitiate(&myList);
	for(i = 0; i < 7; i++)
		ListInsert(&myList, i, a[i]);

	ListMoreDataDelete(&myList, x);

	for(i = 0; i < ListLength(myList); i++)			/*�������˳����е�����*/
	{
		ListGet(myList, i, &x);
		printf("%d   ", x);							/*��ʾ*/
	}	
}

