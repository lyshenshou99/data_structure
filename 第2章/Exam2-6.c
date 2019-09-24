#include <stdio.h>						/*����pringtf()����*/
#include <stdlib.h>						/*����exit()����*/
#include <malloc.h>						/*����malloc()�Ⱥ���*/

typedef int DataType;						/*����DataTypeΪint*/
#include "LinList.h"						/*�����������ļ�*/

void LinListInsert(SLNode *head, DataType x)
{
	SLNode *curr, *pre, *q;
	/*ѭ����ʼ��*/
	curr = head->next;					/*currָ���һ������Ԫ�ؽ��*/
	pre = head;							/*preָ��ͷ���*/

	/*ѭ����λ����λ��*/
	while(curr != NULL && curr->data <= x)
	{
		pre = curr;
		curr = curr->next;
	}

	/*����һ����㲢��x����data��*/
	if((q = (SLNode *)malloc(sizeof(SLNode))) == NULL) exit(1);
	q->data = x;

	/*���½�����pre��ָ����*/
	q->next = pre->next;
	pre->next = q;
}

void main(void)
{
	SLNode *head;					/*����ͷָ�����*/
	int a[] = {3, 8, 2, 4, 1, 5, 7};
	int i , x;

	ListInitiate(&head);					/*��ʼ��*/

	for(i = 0; i < 7; i++)				/*����10������Ԫ��*/
		LinListInsert(head, a[i]);
	
	for(i = 0; i < ListLength(head); i++)	/*��ʾ��ǰ������Ԫ��*/
	{
		ListGet(head, i, &x); 			/*ȡԪ��*/
		printf("%d    ", x);			/*��ʾ*/
	}	
		
	Destroy(&head);						/*����������*/
}
