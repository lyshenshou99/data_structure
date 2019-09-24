#include <stdio.h>						/*����pringtf()����*/
#include <stdlib.h>						/*����exit()����*/
#include <malloc.h>						/*����malloc()�Ⱥ���*/

typedef int DataType;						/*����DataTypeΪint*/
#include "LinList.h"						/*�����������ļ�*/

void show(SLNode *head)
{
	SLNode *p = head->next;								/*pָ����Ԫ���*/

	while(p != NULL)						/*ѭ������*/
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
		
	Destroy(&head);						/*����������*/

}
