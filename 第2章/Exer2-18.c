#include <stdio.h>							/*���ļ�����pringtf()�Ⱥ���*/
#include <stdlib.h>							/*���ļ�����exit()�Ⱥ���*/
#include <malloc.h>							/*���ļ�����malloc()�Ⱥ���*/

typedef int DataType;						/*����DataTypeΪint*/
#include "LinList.h"						/*�������Ա��ļ�*/

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

	ListInitiate(&head);					/*��ʼ��*/
	for(i = 0; i < 10; i++)
	{
		if(ListInsert(head, i, i+1) == 0) 	/*����10������Ԫ��*/
		{
			printf("����! \n");
			return;
		}
	}
	
	Converse(head);

	for(i = 0; i < ListLength(head); i++)
	{
		ListGet(head, i, &x); 		/*ȡԪ��*/
		printf("%d    ", x);			/*��ʾ����Ԫ��*/
	}
	
	Destroy(&head);
}
