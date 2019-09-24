#include <stdio.h>							/*该文件包含pringtf()等函数*/
#include <stdlib.h>

#define MaxQueueSize  100					/*定义MaxQueueSize为100*/
typedef int DataType;						/*定义DataType为int*/
#include "SeqCQueue.h"						/*包含顺序循环队列文件*/

void main(void)
{
	SeqCQueue myQueue;
	int i , x;

	QueueInitiate(&myQueue);					/*初始化*/
	for(i = 0; i < 10; i++)
	{
		if(QueueAppend(&myQueue, i+1) == 0) 		/*入队列10个数据元素*/
		{
			printf("错误! \n");
			return;
		}
	}
	
	if(QueueGet(myQueue, &x) == 0)			/*取队头数据元素*/
	{
		printf("错误! \n");
		return;
	}
	else
		printf("%d\n", x);
		
	QueueDelete(&myQueue, &x);  			/*出队列*/

	printf("依次出队列的数据元素序列如下：\n");
	while(QueueNotEmpty(myQueue))
	{
		QueueDelete(&myQueue, &x);  			/*出队列*/
		printf("%d    ", x);				/*显示数据元素*/
	}	

}
