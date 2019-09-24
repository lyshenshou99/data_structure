#include <stdio.h>							/*该文件包含pringtf()等函数*/
#define MaxSize  100						/*定义MaxSize为100*/
typedef int DataType;						/*定义DataType为int*/
#include "SeqList.h"						/*包含线性表文件*/

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

	ListInitiate(&myList);					/*初始化*/
	for(i = 0; i < 10; i++)
	{
		if(ListInsert(&myList, i, i+1) == 0) 	/*插入10个数据元素*/
		{
			printf("错误! \n");
			return;
		}
	}
	
	if(ListDelete(&myList, 4, &x) == 0) 	/*删除数据元素5*/
	{
		printf("错误! \n");
		return;
	}
	
	for(i = 0; i < ListLength(myList); i++)
	{
		if(ListGet(myList, i, &x) == 0) 		/*取元素*/
		{
			printf("错误! \n");
			return;
		}
		else printf("%d    ", x);			/*显示数据元素*/
	}	
}
