typedef struct
{
	int priority;
	ElemType elem;
}DataType;

typedef struct
{
	DataType queue[MaxQueueSize];
	int size;							/*Ԫ�ظ���*/
} SeqPQueue; 

void QueueInitiate(SeqPQueue *Q)		/*��ʼ��˳�����ȶ���Q*/
{
	Q->size = 0;							/*�����ʼԪ�ظ���*/	
}

int QueueNotEmpty(SeqPQueue Q)
/*��˳�����ȶ���Q�ǿշ񣬷ǿ��򷵻�1�����򷵻�0*/
{
	if(Q.size <= 0)	return 0;
	else return 1;
}

int QueueAppend(SeqPQueue *Q, DataType x)
/*������Ԫ��ֵx����˳�����ȶ���Q�Ķ�β���ɹ�����1��ʧ�ܷ���0 */
{
	if(Q->size >= MaxQueueSize)
	{
		printf("���������޷�����! \n");
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
/*ɾ��˳�����ȶ���Q�����ȼ���ߵ�Ԫ�ز�����d ���ɹ�����1��ʧ�ܷ���0*/
{
	DataType min;
	int minIndex, i;

	if(Q->size <= 0)
	{
		printf("�����ѿ�������Ԫ�س�����! \n");
		return 0;
	}
	else
	{
		min = Q->queue[0];		/*��ʼѡqueue[0]Ϊ���ȼ���ߵ�Ԫ��*/
		minIndex = 0;				/*minIndexΪ���ȼ����Ԫ�ص��±�*/
		for(i = 1; i < Q->size; i++)	/*Ѱ�����ȼ���ߵ�Ԫ�ؼ���Ӧ�±�*/
			if(Q->queue[i].priority < min.priority)
			{
				min = Q->queue[i];
				minIndex = i;
			}

		*d = Q->queue[minIndex];			/*�ҵ������ȼ���ߵ�Ԫ��*/
		for(i = minIndex+1; i < Q->size; i++)	/*����Ԫ������ǰ��*/
			Q->queue[i-1] = Q->queue[i];

		Q->size--;						/*Ԫ�ظ�����1*/	
		return 1;
	}
}

int QueueGet(SeqPQueue *Q, DataType *d)
/*ȡ˳�����ȶ���Q�����ȼ���ߵ�Ԫ�ز�����d ���ɹ�����1��ʧ�ܷ���0*/
{
	DataType min;
	int minIndex, i;

	if(Q->size <= 0)
	{
		printf("�����ѿ�������Ԫ�ؿ�ȡ! \n");
		return 0;
	}
	else
	{
		min = Q->queue[0];		/*��ʼѡqueue[0]Ϊ���ȼ���ߵ�Ԫ��*/
		minIndex = 0;				/*minIndexΪ���ȼ����Ԫ�ص��±�*/
		for(i = 1; i < Q->size; i++)	/*Ѱ�����ȼ���ߵ�Ԫ�ؼ���Ӧ�±�*/
			if(Q->queue[i].priority < min.priority)
			{
				min = Q->queue[i];
				minIndex = i;
			}

		*d = Q->queue[minIndex];	/*�ҵ������ȼ���ߵ�Ԫ��*/
		return 1;
	}
}
