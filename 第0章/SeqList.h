typedef struct
{
	DataType list[MaxSize];			
	int size;
} SeqList;

void ListInitiate(SeqList *L)			/*初始化顺序表L*/
{
	L->size = 0;					/*定义初始数据元素个数*/
}
 
int ListLength(SeqList L)			/*返回顺序表L的当前数据元素个数*/
{
	return L.size;
}

int ListInsert(SeqList *L, int i, DataType x)
/*在顺序表L的位置i（0 ≤ i ≤ size）前插入数据元素值x*/
/*插入成功返回1，插入失败返回0*/
{
	int j;
	if(L->size >= MaxSize)
	{
		printf("顺序表已满无法插入! \n");
		return 0;
	}
	else if(i < 0 || i > L->size )
	{
		printf("参数i不合法! \n");
		return 0;
	}
	else
	{
		for(j = L->size; j > i; j--) L->list[j] = L->list[j-1];		/*为插入做准备*/
		L->list[i] = x;									/*插入*/
		L->size ++;									/*元素个数加1*/
		return 1;
	}
}

int ListGet(SeqList L, int i, DataType *x)
/*取顺序表L中第i个数据元素的值存于x中，成功则返回1，失败返回0*/
{
	if(i < 0 || i > L.size-1)
	{
		printf("参数i不合法! \n");
		return 0;
	}
	else
	{
		*x = L.list[i];
		return 1;
	}
}
