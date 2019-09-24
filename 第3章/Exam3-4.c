#include <stdio.h>
#include <stdlib.h>

#define MaxQueueSize 100
typedef int ElemType;
#include "SeqPQueue.h"

void main(void)
{
	SeqPQueue myPQueue;
	FILE *fp;
	DataType task;
	int i;

	if((fp = fopen("task.dat", "r")) == NULL)
	{
		printf("���ܴ��ļ�task.dat!");
		exit(0);
	}

	QueueInitiate(&myPQueue);
	while(!feof(fp))
	{
		fscanf(fp, "%d %d", &task.elem, &task.priority);
		QueueAppend(&myPQueue, task);
	}


	i = 1;
	printf("���  �����  ���ȼ�\n"); 
	while(QueueNotEmpty(myPQueue))
	{
		QueueDelete(&myPQueue, &task);
		printf("%d       ", i);
		printf("%d       ", task.elem);
		printf("%d     \n", task.priority);
		i++;
	}
}
