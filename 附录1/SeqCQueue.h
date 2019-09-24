/*文件SeqCQueue.h*/
typedef struct
{
	DataType queue[MaxQueueSize];
	int rear;								/*队尾指针*/
	int front;								/*队头指针*/
} SeqCQueue; 

void QueueInitiate(SeqCQueue *Q)		/*初始化顺序循环队列Q*/
{
	Q->rear = 0;						/*定义初始队尾指针下标值*/	
	Q->front = 0;						/*定义初始队头指针下标值*/	
}

int QueueNotEmpty(SeqCQueue Q)
/*判顺序循环队列Q非空否，非空则返回1，否则返回0*/
{
	if(Q.front == Q.rear)	return 0;
	else return 1;
}

int QueueAppend(SeqCQueue *Q, DataType x)
/*把数据元素值x插入顺序循环队列Q的队尾，成功返回1，失败返回0 */
{
	if((Q->rear+1) % MaxQueueSize == Q->front)
	{
		printf("队列已满无法插入! \n");
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
/*删除顺序循环队列Q的队头元素并赋给d ，成功返回1，失败返回0*/
{
	if(Q->front == Q->rear)
	{
		printf("循环队列已空无数据元素出队列! \n");
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
/*取顺序循环队列Q的当前队头元素并赋给d ，成功返回1，失败返回0*/
{
	if(Q.front == Q.rear)
	{
		printf("循环队列已空无数据元素可取! \n");
		return 0;
	}
	else
	{
		*d = Q.queue[Q.front];
		return 1;
	}
}

