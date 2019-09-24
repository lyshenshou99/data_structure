#include <stdio.h>							/*该文件包含pringtf()等函数*/
#include <stdlib.h>							/*该文件包含exit()等函数*/
#include <malloc.h>							/*该文件包含malloc()等函数*/

typedef int DataType;						/*定义DataType为int*/
#include "LinList.h"						/*包含线性表文件*/

void main(void)
{
	SLNode *head;
	int i , x;

	ListInitiate(&head);					/*初始化*/
	for(i = 0; i < 10; i++)
	{
		if(ListInsert(head, i, i+1) == 0) 	/*插入10个数据元素*/
		{
			printf("错误! \n");
			return;
		}
	}
	
	if(ListDelete(head, 4, &x) == 0) 	/*删除数据元素5*/
	{
		printf("错误! \n");
		return;
	}
	
	for(i = 0; i < ListLength(head); i++)
	{
		if(ListGet(head, i, &x) == 0) 		/*取元素*/
		{
			printf("错误! \n");
			return;
		}
		else printf("%d    ", x);			/*显示数据元素*/
	}
	
	Destroy(&head);
}
