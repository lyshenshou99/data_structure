/*�ļ�Palindrome.c*/
#include <string.h>
#include <stdio.h>
#define MaxStackSize 80		/*�����ջ������Ԫ��������*/
#define MaxQueueSize 80		/*������е�����Ԫ��������*/
typedef char DataType;		/*�������Ӧ�õ���������Datatype*/
#include "SeqStack.h"
#include "SeqCQueue.h"	

void Palindrome(char str[], int n)
{
	SeqStack myStack;
	SeqCQueue myQueue;
	char x, y;
	int i;

	StackInitiate(&myStack);
	QueueInitiate(&myQueue);
	for(i = 0; i < n; i++)
	{
		QueueAppend(&myQueue, str[i]);
		StackPush(&myStack, str[i]);
	}

	while(QueueNotEmpty(myQueue) == 1 && StackNotEmpty(myStack) == 1)
	{
		QueueDelete(&myQueue, &x);
		StackPop(&myStack, &y);
		if( x != y) 
		{
			printf("���ǻ���!");
			return;
		}
	}
	printf("�ǻ���!");
}

void EnterStr(char str[], int *n)
{
	printf("�����ַ���(���ܳ���80���ַ�): ");
	scanf("%s", str);
	*n = strlen(str);
}

void main(void)
{
	char ch, str[80];
	int n;

	while(1)
	{
		EnterStr(str, &n);
		Palindrome(str, n);
		printf("\nҪ������?(y/n): ");
		scanf("%s", &ch);
		if(ch == 'Y' || ch == 'y') continue;
		else return;
	}
}
