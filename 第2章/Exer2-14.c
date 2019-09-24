#include <stdio.h>							/*���ļ�����pringtf()�Ⱥ���*/
#include <stdlib.h>							/*���ļ�����exit()�Ⱥ���*/
#include <malloc.h>							/*���ļ�����malloc()�Ⱥ���*/

typedef int DataType;						/*����DataTypeΪint*/
#include "LinList.h"						/*�������Ա��ļ�*/

int ListDeleteMore(SLNode *L, DataType x)
{
	SLNode *pre, *curr, *q;
	int tag = 0;						/*��ʼ��Ϊɾ��ʧ�ܱ��*/

	pre = L;
	curr = L->next;
	while(curr != NULL)
	{
		if(curr->data == x)				/*�ҵ�Ҫɾ����Ԫ��x*/
		{
			q = curr;
			curr = curr->next;
			pre->next = curr;
			free(q);
			tag = 1;
		}
		else							/*����������*/
		{
			pre = curr;
			curr = curr->next;
		}
	}
	return tag;							/*����ɾ���ɹ���ʧ�ܱ��*/
}

void main(void)
{
	SLNode *head;
	int i , x = 89, tag;

	ListInitiate(&head);					/*��ʼ��*/
	for(i = 0; i < 10; i++)
	{
		if(ListInsert(head, i, i+1) == 0) 	/*����10������Ԫ��*/
		{
			printf("����! \n");
			return;
		}
	}
	
	if(ListInsert(head, 5, 8) == 0) 	/*ɾ������Ԫ��5*/
	{
		printf("����! \n");
		return;
	}
	
	tag = ListDeleteMore(head, x);
	printf("tag = %d\n",tag);

	for(i = 0; i < ListLength(head); i++)
	{
		ListGet(head, i, &x); 		/*ȡԪ��*/
		printf("%d    ", x);			/*��ʾ����Ԫ��*/
	}
	
	Destroy(&head);
}
