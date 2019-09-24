typedef struct qnode
{
	ElemType data;
	struct qnode *next;
} LQNode; 						

typedef struct
{
	LQNode *front;							/*��ͷָ��*/
	LQNode *rear;							/*��βָ��*/
} LQueue;

void QueueInitiate(LQueue *Q)				/*��ʼ����ʽ����Q*/
{
	Q->rear = NULL;					/*�����ʼ��βָ���±�ֵ*/	
	Q->front = NULL;					/*�����ʼ��ͷָ���±�ֵ*/	
}

int QueueNotEmpty(LQueue Q)
/*����ʽ����Q�ǿշ񣬷ǿ��򷵻�1�����򷵻�0*/
{
	if(Q.front == NULL) return 0;
	else return 1;
}

int QueueAppend(LQueue *Q, ElemType x)
/*������Ԫ��ֵx������ʽ����Q�Ķ�β������гɹ��򷵻�1�����򷵻�0 */
{
	LQNode *p;
	if((p = (LQNode *)malloc(sizeof(LQNode))) == NULL) 
	{
		printf("�ڴ�ռ䲻�㣡");
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
/*ɾ����ʽ����Q�Ķ�ͷ����Ԫ��ֵ��d �������гɹ��򷵻�1�����򷵻�0*/
{
	LQNode *p;
	if(Q->front == NULL)
	{
		printf("�����ѿ�������Ԫ�س�����! \n");
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
/*ȡ��ʽ����Q�ĵ�ǰ��ͷ����Ԫ��ֵ��d ���ɹ��򷵻�1�����򷵻�0*/
{
	if(Q.front == NULL)
	{
		printf("�����ѿ�������Ԫ�س�����! \n");
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
