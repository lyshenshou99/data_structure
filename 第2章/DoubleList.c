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
	(*head)->prior = *head;					/*����ǰ��ָ��ѭ����*/
	(*head)->next = *head;					/*���ɺ��ָ��ѭ����*/
}

int ListInsert(DLNode *head, int i, DataType x)
{
	DLNode *p, *s;
	int j;

	p = head->next;
	j = 0;
	while(p != head && j < i)   				/* Ѱ�ҵ�i����� */
	{
   		p = p->next;
   		j++;
	}

	if(j != i)
	{
		printf("����λ�ò�������!");
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
	while(p->next != head && j < i)   		/* Ѱ�ҵ�i����� */
	{
		p = p->next;
		j++;
	}

	if(j != i)
	{
		printf("ɾ��λ�ò�������!");
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
   while(p->next != head && j < i)   /* Ѱ�ҵ�i�����, pָ����ǰ�� */
   {
      p = p->next;
      j++;
   }

   if(j != i)
   {
      printf("λ�ò�������!");
      return 0;
   }

   *x = p->data; 
   return 1;
}

int ListLength(DLNode *head)
{
	DLNode *p = head->next;							/*pָ����Ԫ���*/
	int size = 0;									/*size��ʼΪ0*/

	while(p != head)						/*ѭ������*/
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

	ListInitiate(&head);					/*��ʼ��*/
	for(i = 0; i < 10; i++)
	{
		if(ListInsert(head, i, i+1) == 0) 	/*����10������Ԫ��*/
		{
			printf("����! \n");
			return;
		}
	}
	
	if(ListDelete(head, 4, &x) == 0) 	/*ɾ������Ԫ��5*/
	{
		printf("����! \n");
		return;
	}
	
	for(i = 0; i < ListLength(head); i++)
	{
		if(ListGet(head, i, &x) == 0) 		/*ȡԪ��*/
		{
			printf("����! \n");
			return;
		}
		else printf("%d    ", x);			/*��ʾ����Ԫ��*/
	}	
	Destroy(&head);
}
