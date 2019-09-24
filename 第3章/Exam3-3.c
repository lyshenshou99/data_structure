#include <stdio.h>
#include <string.h>

#define MaxQueueSize 100
#define MaxStackSize 100
typedef char DataType;			//�������Ӧ�õ���������Datatype
#include "SeqCQueue.h"
#include "SeqStack.h"

void HuiWen(char str[])
{
	SeqCQueue myQueue;
	SeqStack myStack;
	char x, y;
	int i, length;
	
	length = strlen(str);
	QueueInitiate(&myQueue);
	StackInitiate(&myStack);
	for(i = 0; i < length; i++)
	{
		QueueAppend(&myQueue, str[i]);
		StackPush(&myStack, str[i]);
	}

	while(QueueNotEmpty(myQueue) == 1 && StackNotEmpty(myStack) == 1)
	{
		if(QueueDelete(&myQueue, &x) == 1 
			&& StackPop(&myStack, &y) == 1 && x != y) 
		{
			printf("%s���ǻ���!\n", str);
			return;
		}
	}

	if(QueueNotEmpty(myQueue) || StackNotEmpty(myStack))
		printf("%s���ǻ���!\n", str);
	else
		printf("%s�ǻ���!\n", str);
}

void main(void)
{
	char str1[] = "ABCDEDCBA";
	char str2[] = "ABCDEDCAB";
	
	HuiWen(str1);
	HuiWen(str2);
}
