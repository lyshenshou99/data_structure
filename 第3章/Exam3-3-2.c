#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef char DataType;		/*�������Ӧ�õ���������Datatype*/
#include "LinQueue.h"		/*������ʽ�����ļ�*/
#include "LinStack.h"		/*������ʽ��ջ�ļ�*/

void main(void)
{
	LQueue queueHead;
	LSNode *stackHead;
	char str[] = "ABCDEDCBA", x, y;
	int i, length = 9;
	
	QueueInitiate(&queueHead);				/*���г�ʼ��*/
	StackInitiate(&stackHead);				/*��ջ��ʼ��*/
	for(i = 0; i < length; i++)
	{
		QueueAppend(&queueHead, str[i]);
		StackPush(stackHead, str[i]);
	}

	while(QueueNotEmpty(queueHead) == 1)
	{
		if(QueueDelete(&queueHead, &x) == 1 
			&& StackPop(stackHead, &y) == 1 && x != y) 
		{
			printf("���ǻ���!\n");
			return;
		}
	}
	printf("�ǻ���!\n");
}
