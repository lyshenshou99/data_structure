typedef struct qnode
{
	ElemType data;
	struct qnode *next;
} LQNode; 						

typedef struct
{
	LQNode *front;							/*队头指针*/
	LQNode *rear;							/*队尾指针*/
} LQueue;

void QueueInitiate(LQueue *Q)				/*初始化链式队列Q*/
{
	Q->rear = NULL;					/*定义初始队尾指针下标值*/	
	Q->front = NULL;					/*定义初始队头指针下标值*/	
}

int QueueNotEmpty(LQueue Q)
/*判链式队列Q非空否，非空则返回1，否则返回0*/
{
	if(Q.front == NULL) return 0;
	else return 1;
}

int QueueAppend(LQueue *Q, ElemType x)
/*把数据元素值x插入链式队列Q的队尾，入队列成功则返回1，否则返回0 */
{
	LQNode *p;
	if((p = (LQNode *)malloc(sizeof(LQNode))) == NULL) 
	{
		printf("内存空间不足！");
		return 0;
	}
	
	p->data = x;
	p->next = NULL;
	
	if(Q->rear != NULL) Q->rear->next = p;
	Q->rear = p;
	if(Q->front == NULL) Q->front = p;
	return 1;
}

int QueueDelete(LQueue *Q, ElemType *d)
/*删除链式队列Q的队头数据元素值到d ，出队列成功则返回1，否则返回0*/
{
	LQNode *p;
	if(Q->front == NULL)
	{
		printf("队列已空无数据元素出队列! \n");
		return 0;
	}
	else
	{
		*d = Q->front->data;
		p = Q->front;
		Q->front = Q->front->next;
		if(Q->front == NULL) Q->rear = NULL;
		free(p);
		return 1;
	}
}

int QueueGet(LQueue Q, ElemType *d)
/*取链式队列Q的当前队头数据元素值到d ，成功则返回1，否则返回0*/
{
	if(Q.front == NULL)
	{
		printf("队列已空无数据元素出队列! \n");
		return 0;
	}
	else
	{
		*d = Q.front->data;
		return 1;
	}
}

void Destroy(LQueue Q)
{
	LQNode *p, *p1;

	p = Q.front;
	while(p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}
