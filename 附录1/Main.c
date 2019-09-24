/*�ļ�Main.c*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int number;
	int cipher;
} DataType;							/*����������������DataType*/

#include "SCLinList.h"					/*����SCLinList������������*/

void SCLLDeleteAfter(SCLNode *p)	/*ɾ��pָ����ָ������һ�����*/
{
	SCLNode *q = p->next;
	p->next = p->next->next;
	free(q);
}

void JesephRing(SCLNode *head, int m)
/*�Դ�ͷ��㵥ѭ������head����ʼֵΪm��Լɪ�����⺯��*/
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

	SCLLInitiate(&head);					/*��ʼ��*/
	for(i = 1; i <= n; i++)					/*ѭ�����뽨����ѭ������*/
		SCLLInsert(head, i, test[i-1]);

	JesephRing(head, m);					/*����Լɪ�����⺯��*/
}
