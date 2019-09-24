/*文件Main.c*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int number;
	int cipher;
} DataType;							/*定义具体的数据类型DataType*/

#include "SCLinList.h"					/*包含SCLinList抽象数据类型*/

void SCLLDeleteAfter(SCLNode *p)	/*删除p指针所指结点的下一个结点*/
{
	SCLNode *q = p->next;
	p->next = p->next->next;
	free(q);
}

void JesephRing(SCLNode *head, int m)
/*对带头结点单循环链表head，初始值为m的约瑟夫环问题函数*/
{
	SCLNode *pre, *curr;
	int i;

	pre = head;
	curr = head->next;
	while(SCLLNotEmpty(head) == 1)
	{
		for(i = 1; i < m; i++)
		{
			pre = curr;
			curr = curr->next;
			if(curr == head)
			{
				pre = curr;
				curr = curr->next;
			}
		}
		
		printf(" %d   ", curr->data.number);
		m = curr->data.cipher;

		curr = curr->next;
		if(curr == head) curr = curr->next;

		SCLLDeleteAfter(pre);
	}
}

void main(void)
{
	DataType test[7]={{1,3},{2,1},{3,7},{4,2},{5,4},{6,8},{7,4}};
	int n = 7, m = 20, i;
	SCLNode *head;

	SCLLInitiate(&head);					/*初始化*/
	for(i = 1; i <= n; i++)					/*循环插入建立单循环链表*/
		SCLLInsert(head, i, test[i-1]);

	JesephRing(head, m);					/*调用约瑟夫环问题函数*/
}
