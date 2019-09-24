#include <stdio.h>

#define MaxQueueSize 100
typedef int ElemType;
#include "SeqPQueue.h"

void main(void)
{
   SeqPQueue myPQueue;
   DataType temp = {5}, x;
   int i;

	QueueInitiate(&myPQueue);
   //»Î
   for(i=0; i<5; i++)
   {
	  QueueAppend(&myPQueue, temp);
	  temp.priority--;
   }

   //≥ˆ
	printf("size = %d\n", myPQueue.size);
   while(QueueNotEmpty(myPQueue) == 1)
   {
	  QueueDelete(&myPQueue, &x);
		printf("%d   ", x);
   }
}