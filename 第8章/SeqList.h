typedef struct
{
	DataType list[MaxSize];			
	int size;
} SeqList;

void ListInitiate(SeqList *L)			/*��ʼ��˳���L*/
{
	L->size = 0;					/*�����ʼ����Ԫ�ظ���*/
}
 
int ListLength(SeqList L)			/*����˳���L�ĵ�ǰ����Ԫ�ظ���*/
{
	return L.size;
}

int ListInsert(SeqList *L, int i, DataType x)
/*��˳���L��λ��i��0 �� i �� size��ǰ��������Ԫ��ֵx*/
/*����ɹ�����1������ʧ�ܷ���0*/
{
	int j;
	if(L->size >= MaxSize)
	{
		printf("˳��������޷�����! \n");
		return 0;
	}
	else if(i < 0 || i > L->size )
	{
		printf("����i���Ϸ�! \n");
		return 0;
	}
	else
	{
		for(j = L->size; j > i; j--) L->list[j] = L->list[j-1];		/*Ϊ������׼��*/
		L->list[i] = x;									/*����*/
		L->size ++;									/*Ԫ�ظ�����1*/
		return 1;
	}
}

int ListDelete(SeqList *L, int i, DataType *x)	
/*ɾ��˳���L��λ��i��0 �� i �� size - 1��������Ԫ��ֵ����ŵ�����x��*/
/*ɾ���ɹ�����1��ɾ��ʧ�ܷ���0*/
{
	int j;
	if(L->size <= 0)
	{
		printf("˳����ѿ�������Ԫ�ؿ�ɾ! \n");
		return 0;
	}
	else if(i < 0 || i > L->size-1)
	{
		printf("����i���Ϸ�");
		return 0;
	}
	else
	{
		*x = L->list[i];					/*����ɾ����Ԫ�ص�����x��*/
		for(j = i +1; j <= L->size-1; j++) L->list[j-1] = L->list[j];	/*����ǰ��*/
		L->size--;						/*����Ԫ�ظ�����1*/
		return 1;
	}
}

int ListGet(SeqList L, int i, DataType *x)
/*ȡ˳���L�е�i������Ԫ�ص�ֵ����x�У��ɹ��򷵻�1��ʧ�ܷ���0*/
{
	if(i < 0 || i > L.size-1)
	{
		printf("����i���Ϸ�! \n");
		return 0;
	}
	else
	{
		*x = L.list[i];
		return 1;
	}
}
