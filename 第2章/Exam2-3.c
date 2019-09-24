#include <stdio.h>							/*���ļ�����pringtf()�Ⱥ���*/
#include <stdlib.h>							/*���ļ�����exit()�Ⱥ���*/
#include <malloc.h>							/*���ļ�����malloc()�Ⱥ���*/

typedef int DataType;						/*����DataTypeΪint*/
#include "LinList.h"						/*�������Ա��ļ�*/

void main(void)
{
	SLNode *head;
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
