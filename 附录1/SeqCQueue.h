/*�ļ�SeqCQueue.h*/
typedef struct
{
	DataType queue[MaxQueueSize];
	int rear;								/*��βָ��*/
	int front;								/*��ͷָ��*/
} SeqCQueue; 

void QueueInitiate(SeqCQueue *Q)		/*��ʼ��˳��ѭ������Q*/
{
	Q->rear = 0;						/*�����ʼ��βָ���±�ֵ*/	
	Q->front = 0;						/*�����ʼ��ͷָ���±�ֵ*/	
}

int QueueNotEmpty(SeqCQueue Q)
/*��˳��ѭ������Q�ǿշ񣬷ǿ��򷵻�1�����򷵻�0*/
{
	if(Q.front == Q.rear)	return 0;
	else return 1;
}

int QueueAppend(SeqCQueue *Q, DataType x)
/*������Ԫ��ֵx����˳��ѭ������Q�Ķ�β���ɹ�����1��ʧ�ܷ���0 */
{
	if((Q->rear+1) % MaxQueueSize == Q->front)
	{
		printf("���������޷�����! \n");
		return 0;
	}
	else
	{
		Q->queue[Q->rear] = x;
		Q->rear = (Q->rear + 1) % MaxQueueSize;
		return 1;
	}
}

int QueueDelete(SeqCQueue *Q, DataType *d)
/*ɾ��˳��ѭ������Q�Ķ�ͷԪ�ز�����d ���ɹ�����1��ʧ�ܷ���0*/
{
	if(Q->front == Q->rear)
	{
		printf("ѭ�������ѿ�������Ԫ�س�����! \n");
		return 0;
	}
	else
	{
		*d = Q->queue[Q->front];
		Q->front = (Q->front + 1) % MaxQueueSize;
		return 1;
	}
}

int QueueGet(SeqCQueue Q, DataType *d)
/*ȡ˳��ѭ������Q�ĵ�ǰ��ͷԪ�ز�����d ���ɹ�����1��ʧ�ܷ���0*/
{
	if(Q.front == Q.rear)
	{
		printf("ѭ�������ѿ�������Ԫ�ؿ�ȡ! \n");
		return 0;
	}
	else
	{
		*d = Q.queue[Q.front];
		return 1;
	}
}

