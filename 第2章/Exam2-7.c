#include <stdio.h>						/*����pringtf()����*/
#include <stdlib.h>						/*����exit()����*/
#include <malloc.h>						/*����malloc()�Ⱥ���*/

typedef int DataType;						/*����DataTypeΪint*/
#include "LinList.h"						/*�����������ļ�*/

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
	SLNode *head;					/*����ͷָ�����*/
	int a[] = {3, 8, 2, 4, 1, 5, 7};
	int i , x;

	ListInitiate(&head);					/*��ʼ��*/

	for(i = 0; i < 7; i++)				/*����10������Ԫ��*/
		ListInsert(head, i, a[i]);

	LinListSort(head);
	
	for(i = 0; i < ListLength(head); i++)	/*��ʾ��ǰ������Ԫ��*/
	{
		ListGet(head, i, &x); 			/*ȡԪ��*/
		printf("%d    ", x);			/*��ʾ*/
	}	
		
	Destroy(&head);						/*����������*/
}
