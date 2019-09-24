#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node *prior;
	struct Node *next;
}DLNode;

void ListInitiate(DLNode **head)
{
	if((*head = (DLNode *)malloc(sizeof(DLNode))) == NULL) exit(0);
	(*head)->prior = *head;					/*构成前驱指针循环链*/
	(*head)->next = *head;					/*构成后继指针循环链*/
}

int ListInsert(DLNode *head, int i, DataType x)
{
	DLNode *p, *s;
	int j;

	p = head->next;
	j = 0;
	while(p != head && j < i)   				/* 寻找第i个结点 */
	{
   		p = p->next;
   		j++;
	}

	if(j != i)
	{
		printf("插入位置参数出错!");
   		return 0;
	}

	if((s = (DLNode *)malloc(sizeof(DLNode))) == NULL) exit(0);

	s->data = x;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;

	return 1;
}

int ListDelete(DLNode *head, int i, DataType *x)
{
	DLNode *p;
	int j;

	p = head->next;
	j = 0;
	while(p->next != head && j < i)   		/* 寻找第i个结点 */
	{
		p = p->next;
		j++;
	}

	if(j != i)
	{
		printf("删除位置参数出错!");
		return 0;
	}

	p->prior->next = p->next;
	p->next->prior = p->prior;

	free(p); 
	return 1;
}

int ListGet(DLNode *head, int i, DataType *x)
{
   DLNode *p;
   int j;

   p = head->next;
   j = 0;
   while(p->next != head && j < i)   /* 寻找第i个结点, p指向其前驱 */
   {
      p = p->next;
      j++;
   }

   if(j != i)
   {
      printf("位置参数出错!");
      return 0;
   }

   *x = p->data; 
   return 1;
}

int ListLength(DLNode *head)
{
	DLNode *p = head->next;							/*p指向首元结点*/
	int size = 0;									/*size初始为0*/

	while(p != head)						/*循环计数*/
	{
		p = p->next;
		size ++;
	}
	return size;
}

void Destroy(DLNode **head)
{
	DLNode *p, *p1;
	int i, n = ListLength(*head);

	p = *head;
	for(i = 0; i <= n; i++)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}

	*head = NULL;
}

void main(void)
{
	DLNode *head;
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
