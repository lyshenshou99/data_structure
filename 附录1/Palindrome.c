/*文件Palindrome.c*/
#include <string.h>
#include <stdio.h>
#define MaxStackSize 80		/*定义堆栈的数据元素最大个数*/
#define MaxQueueSize 80		/*定义队列的数据元素最大个数*/
typedef char DataType;		/*定义具体应用的数据类型Datatype*/
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
			printf("不是回文!");
			return;
		}
	}
	printf("是回文!");
}

void EnterStr(char str[], int *n)
{
	printf("输入字符串(不能超过80个字符): ");
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
		printf("\n要继续吗?(y/n): ");
		scanf("%s", &ch);
		if(ch == 'Y' || ch == 'y') continue;
		else return;
	}
}
