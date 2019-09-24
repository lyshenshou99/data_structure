#include <stdio.h>						/*包含pringtf()函数*/
#include <stdlib.h>						/*包含exit()函数*/
#include <malloc.h>						/*包含malloc()等函数*/

typedef int DataType;						/*定义DataType为int*/
#include "LinList.h"						/*包含单链表文件*/

void LinListSort(SLNode *head)
{
	SLNode *curr, *pre, *p, *q;
	p = head->next;
	head->next = NULL;

	while(p != NULL)
	{
		curr = head->next;
		pre = head;
		while(curr != NULL && curr->data <= p->data)
		{
			pre = curr;
			curr = curr->next;
		}
		q = p;
		p = p->next;
 		q->next = pre->next;
		pre->next = q;
	}
}

void main(void)
{
	SLNode *head;					/*定义头指针变量*/
	int a[] = {3, 8, 2, 4, 1, 5, 7};
	int i , x;

	ListInitiate(&head);					/*初始化*/

	for(i = 0; i < 7; i++)				/*插入10个数据元素*/
		ListInsert(head, i, a[i]);

	LinListSort(head);
	
	for(i = 0; i < ListLength(head); i++)	/*显示当前的数据元素*/
	{
		ListGet(head, i, &x); 			/*取元素*/
		printf("%d    ", x);			/*显示*/
	}	
		
	Destroy(&head);						/*撤消单链表*/
}
