#include <stdio.h>							/*该文件包含pringtf()等函数*/
#include <stdlib.h>							/*该文件包含exit()等函数*/
#include <malloc.h>							/*该文件包含malloc()等函数*/

typedef int DataType;						/*定义DataType为int*/
#include "LinList.h"						/*包含线性表文件*/

void Converse(SLNode *head)
{
	SLNode *p, *q;

	p = head->next;
	head->next = NULL;
	while(p != NULL)
	{
		q = p;
		p = p->next;
		q->next = head->next;
		head->next = q;;
	}
}

void main(void)
{
	SLNode *head;
	int i, x;

	ListInitiate(&head);					/*初始化*/
	for(i = 0; i < 10; i++)
	{
		if(ListInsert(head, i, i+1) == 0) 	/*插入10个数据元素*/
		{
			printf("错误! \n");
			return;
		}
	}
	
	Converse(head);

	for(i = 0; i < ListLength(head); i++)
	{
		ListGet(head, i, &x); 		/*取元素*/
		printf("%d    ", x);			/*显示数据元素*/
	}
	
	Destroy(&head);
}
