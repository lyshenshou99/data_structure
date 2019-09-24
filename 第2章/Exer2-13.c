#include <stdio.h>							/*该文件包含pringtf()等函数*/
#define MaxSize  100						/*定义MaxSize为100*/
typedef int DataType;						/*定义DataType为int*/
#include "SeqList.h"						/*包含线性表文件*/

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

	ListInitiate(&myList);					/*初始化*/
	for(i = 0; i < 10; i++)
	{
		if(ListInsert(&myList, i, i+1) == 0) 	/*插入10个数据元素*/
		{
			printf("错误! \n");
			return;
		}
	}
	
	i = ListFind(myList, x);
	printf("i = %d\n", i);
	
}
