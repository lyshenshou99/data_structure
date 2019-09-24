#include <stdio.h>						/*包含pringtf()函数*/
#include <stdlib.h>						/*包含exit()函数*/
#include <malloc.h>						/*包含malloc()等函数*/

typedef int DataType;						/*定义DataType为int*/
#include "LinList.h"						/*包含单链表文件*/

void LinListInsert(SLNode *head, DataType x)
{
	SLNode *curr, *pre, *q;
	/*循环初始化*/
	curr = head->next;					/*curr指向第一个数据元素结点*/
	pre = head;							/*pre指向头结点*/

	/*循环定位插入位置*/
	while(curr != NULL && curr->data <= x)
	{
		pre = curr;
		curr = curr->next;
	}

	/*申请一个结点并把x存入data域*/
	if((q = (SLNode *)malloc(sizeof(SLNode))) == NULL) exit(1);
	q->data = x;

	/*把新结点插入pre所指结点后*/
	q->next = pre->next;
	pre->next = q;
}

void main(void)
{
	SLNode *head;					/*定义头指针变量*/
	int a[] = {3, 8, 2, 4, 1, 5, 7};
	int i , x;

	ListInitiate(&head);					/*初始化*/

	for(i = 0; i < 7; i++)				/*插入10个数据元素*/
		LinListInsert(head, a[i]);
	
	for(i = 0; i < ListLength(head); i++)	/*显示当前的数据元素*/
	{
		ListGet(head, i, &x); 			/*取元素*/
		printf("%d    ", x);			/*显示*/
	}	
		
	Destroy(&head);						/*撤消单链表*/
}
