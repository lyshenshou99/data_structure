#include <stdio.h>							/*���ļ�����pringtf()�Ⱥ���*/
#define MaxSize  100						/*����MaxSizeΪ100*/
typedef int DataType;						/*����DataTypeΪint*/
#include "SeqList.h"						/*�������Ա��ļ�*/

int ListFind(SeqList L, DataType x)
{
	int i;
	for(i = 0; i < L.size; i++)
	{
		if(L.data[i] == x) return i;
		else continue;
	}
	return -1;
}

void main(void)
{
	SeqList myList;
	int i , x;

	ListInitiate(&myList);					/*��ʼ��*/
	for(i = 0; i < 10; i++)
	{
		if(ListInsert(&myList, i, i+1) == 0) 	/*����10������Ԫ��*/
		{
			printf("����! \n");
			return;
		}
	}
	
	if(ListDelete(&myList, 4, &x) == 0) 	/*ɾ������Ԫ��5*/
	{
		printf("����! \n");
		return;
	}
	
	for(i = 0; i < ListLength(myList); i++)
	{
		if(ListGet(myList, i, &x) == 0) 		/*ȡԪ��*/
		{
			printf("����! \n");
			return;
		}
		else printf("%d    ", x);			/*��ʾ����Ԫ��*/
	}	
}
