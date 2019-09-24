#include <stdio.h>							/*���ļ�����pringtf()����*/
#include <stdlib.h>							/*���ļ�����exit()����*/
#include <malloc.h>
typedef int DataType;						/*����DataTypeΪint*/
#include "LinStack.h"

void main(void)
{
	LSNode *head;
	int i , x;

	StackInitiate(&head);					/*��ʼ��*/
	for(i = 0; i < 10; i++)
	{
		if(StackPush(head, i+1) == 0) 		/*��ջ10������Ԫ��*/
		{
			printf("����! \n");
			return;
		}
	}
	
	if(StackTop(head, &x) == 0) 		/*ȡջ������Ԫ��*/
	{
		printf("����! \n");
		return;
	}
	else
		printf("%d\n", x);
		
	printf("���γ�ջ������Ԫ���������£�\n");
	while(StackNotEmpty(head))
	{
		StackPop(head, &x); 			/*��ջ*/
		printf("%d    ", x);			/*��ʾ����Ԫ��*/
	}	
}
