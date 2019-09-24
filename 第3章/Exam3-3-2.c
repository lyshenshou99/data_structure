#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef char DataType;		/*定义具体应用的数据类型Datatype*/
#include "LinQueue.h"		/*包含链式队列文件*/
#include "LinStack.h"		/*包含链式堆栈文件*/

void main(void)
{
	LQueue queueHead;
	LSNode *stackHead;
	char str[] = "ABCDEDCBA", x, y;
	int i, length = 9;
	
	QueueInitiate(&queueHead);				/*队列初始化*/
	StackInitiate(&stackHead);				/*堆栈初始化*/
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
			printf("不是回文!\n");
			return;
		}
	}
	printf("是回文!\n");
}
