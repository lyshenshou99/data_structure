#include <stdio.h>							/*���ļ�����pringtf()�Ⱥ���*/
#define MaxSize  100						/*����MaxSizeΪ100*/
typedef int DataType;						/*����DataTypeΪint*/
#include "SeqList.h"						/*�������Ա��ļ�*/

int ListFind(SeqList L, DataType x)
{
	int i;
	for(i = 0; i < L.size; i++)
	{
		if(L.list[i] == x) return i;
		else continue;
	}
	return -1;
}

void main(void)
{
	SeqList myList;
	int i , x = 89;

	ListInitiate(&myList);					/*��ʼ��*/
	for(i = 0; i < 10; i++)
	{
		if(ListInsert(&myList, i, i+1) == 0) 	/*����10������Ԫ��*/
		{
			printf("����! \n");
			return;
		}
	}
	
	i = ListFind(myList, x);
	printf("i = %d\n", i);
	
}
