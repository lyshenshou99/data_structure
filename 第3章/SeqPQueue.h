typedef struct
{
	int priority;
	ElemType elem;
}DataType;

typedef struct
{
	DataType queue[MaxQueueSize];
	int size;							/*元素个数*/
} SeqPQueue; 

void QueueInitiate(SeqPQueue *Q)		/*初始化顺序优先队列Q*/
{
	Q->size = 0;							/*定义初始元素个数*/	
}

int QueueNotEmpty(SeqPQueue Q)
/*判顺序优先队列Q非空否，非空则返回1，否则返回0*/
{
	if(Q.size <= 0)	return 0;
	else return 1;
}

int QueueAppend(SeqPQueue *Q, DataType x)
/*把数据元素值x插入顺序优先队列Q的队尾，成功返回1，失败返回0 */
{
	if(Q->size >= MaxQueueSize)
	{
		printf("队列已满无法插入! \n");
		return 0;
	}
	else
	{
		Q->queue[Q->size] = x;
		Q->size ++;
		return 1;
	}
}

int QueueDelete(SeqPQueue *Q, DataType *d)
/*删除顺序优先队列Q中优先级最高的元素并赋给d ，成功返回1，失败返回0*/
{
	DataType min;
	int minIndex, i;

	if(Q->size <= 0)
	{
		printf("队列已空无数据元素出队列! \n");
		return 0;
	}
	else
	{
		min = Q->queue[0];		/*初始选queue[0]为优先级最高的元素*/
		minIndex = 0;				/*minIndex为优先级最高元素的下标*/
		for(i = 1; i < Q->size; i++)	/*寻找优先级最高的元素即对应下标*/
			if(Q->queue[i].priority < min.priority)
			{
				min = Q->queue[i];
				minIndex = i;
			}

		*d = Q->queue[minIndex];			/*找到的优先级最高的元素*/
		for(i = minIndex+1; i < Q->size; i++)	/*数据元素依次前移*/
			Q->queue[i-1] = Q->queue[i];

		Q->size--;						/*元素个数减1*/	
		return 1;
	}
}

int QueueGet(SeqPQueue *Q, DataType *d)
/*取顺序优先队列Q中优先级最高的元素并赋给d ，成功返回1，失败返回0*/
{
	DataType min;
	int minIndex, i;

	if(Q->size <= 0)
	{
		printf("队列已空无数据元素可取! \n");
		return 0;
	}
	else
	{
		min = Q->queue[0];		/*初始选queue[0]为优先级最高的元素*/
		minIndex = 0;				/*minIndex为优先级最高元素的下标*/
		for(i = 1; i < Q->size; i++)	/*寻找优先级最高的元素即对应下标*/
			if(Q->queue[i].priority < min.priority)
			{
				min = Q->queue[i];
				minIndex = i;
			}

		*d = Q->queue[minIndex];	/*找到的优先级最高的元素*/
		return 1;
	}
}
