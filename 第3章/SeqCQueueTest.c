#include <stdio.h>							/*���ļ�����pringtf()�Ⱥ���*/
#include <stdlib.h>

#define MaxQueueSize  100					/*����MaxQueueSizeΪ100*/
typedef int DataType;						/*����DataTypeΪint*/
#include "SeqCQueue.h"						/*����˳��ѭ�������ļ�*/

void main(void)
{
	SeqCQueue myQueue;
	int i , x;

	QueueInitiate(&myQueue);					/*��ʼ��*/
	for(i = 0; i < 10; i++)
	{
		if(QueueAppend(&myQueue, i+1) == 0) 		/*�����10������Ԫ��*/
		{
			printf("����! \n");
			return;
		}
	}
	
	if(QueueGet(myQueue, &x) == 0)			/*ȡ��ͷ����Ԫ��*/
	{
		printf("����! \n");
		return;
	}
	else
		printf("%d\n", x);
		
	QueueDelete(&myQueue, &x);  			/*������*/

	printf("���γ����е�����Ԫ���������£�\n");
	while(QueueNotEmpty(myQueue))
	{
		QueueDelete(&myQueue, &x);  			/*������*/
		printf("%d    ", x);				/*��ʾ����Ԫ��*/
	}	

}
