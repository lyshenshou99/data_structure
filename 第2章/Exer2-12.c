#include <stdio.h>						/*包含pringtf()函数*/
#include <stdlib.h>						/*包含exit()函数*/
#include <malloc.h>						/*包含malloc()等函数*/

typedef int DataType;						/*定义DataType为int*/
#include "LinList.h"						/*包含单链表文件*/

void show(SLNode *head)
{
	SLNode *p = head->next;								/*p指向首元结点*/

	while(p != NULL)						/*循环计数*/
	{
		printf("%d   ", p->data);
		p = p->next;
	}
}

void main(void)
{
	SLNode *head;					
	int a[] = {3, 8, 2, 4, 1, 5, 7};
	int i , x;

	ListInitiate(&head);					
	for(i = 0; i < 7; i++)		
		ListInsert(head, i, a[i]);
	
	show(head);	
		
	Destroy(&head);						/*撤消单链表*/

}
