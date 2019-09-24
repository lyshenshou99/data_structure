#include <stdio.h>
#include <stdlib.h>
typedef int DataType;

#include "LinQueue.h"

void main(void)
{
	LQueue myQueue;
	int i , x;

	QueueInitiate(&myQueue);
	for(i = 1; i <= 10; i++)
		QueueAppend(&myQueue, i);

	QueueDelete(&myQueue, &x);
	
	while(QueueNotEmpty(myQueue) == 1)
	{
		if(QueueGet(myQueue, &x) == 0) 
		{
			printf("´íÎó! \n");
			return;
		}
		else 
		{
			printf("%d    ", x);
			QueueDelete(&myQueue, &x);
		}
	}
	Destroy(myQueue);
}