#include<stdio.h>

typedef struct
{
	long  number;				/*学号数据项*/
	char  name[10];			    /*姓名数据项*/
	char  sex[3];				/*性别数据项*/
	int   age;					/*年龄数据项*/
	float grade;				/*成绩数据项*/
} StudentType;

typedef StudentType DataType;

#define MaxSize 100

typedef struct
{
	DataType list[MaxSize];
	int size;
}SeqList;

void ListInitiate(SeqList* L)			/*初始化函数*/ 
{
	L->size = 0;
}

int ListLength(SeqList L)			/*求数组当前元素个数函数*/ 
{
	return L.size;
}

int ListInsert(SeqList* L, int i, DataType x) /*在数组的位置i前插入数据元素x函数*/
{
	int j = 0;
	
	if(L->size >= MaxSize)
	{
		printf("顺序表已满无法插入\n");
		
		return 0;
	}
	else if(i < 0 || i > L->size)
	{
		printf("参数i不合法！\n");
		
		return 0;
	}
	else
	{
		for(j = L->size; j > i; j--) L->list[j] = L->list[j - 1];
		
		L->list[i] = x;
		L->size++;
		
		return 1;
	}
 } 
 
 int ListDelete(SeqList* L, int i, DataType *x)  /*删除顺序表L中位置为i的数据元素并存放到x中*/
 {
 	int j = 0;
	
 	if(L->size <= 0)
 	{
 		printf("顺序表已空无数据元素可删！\n");
		
		return 0;	  
	}
	else if(i < 0 || i > L->size - 1)
	{
		printf("参数i不合法！\n");
		
		return 0;
	}
	else
	{
		*x = L->list[i];
		
		for(j = i+1; j <= L->size - 1; j++) L->list[j - 1] = L->list[j];
		
		L->size--;
		
		return 1; 
	}
}
 
 int ListGet(SeqList L, int i, DataType* x)		/*取顺序表L中的第i个数据元素存于x中*/ 
 {
 	if(i < 0 || i > L.size - 1)
	 {
	 	printf("参数i不合法！\n");
		
	 	return 0;
	  } 
	  else
	  {
	  	*x = L.list[i];	
		
	  	return 1;
	  }
 }
 
void ListExchange(SeqList* L, int i, int j)
 {
 	DataType temp;
 	
 	temp = L->list[i];
 	L->list[i] = L->list[j];
 	L->list[j] = temp;
 }
 
 void ListExchangeAsGrade(SeqList* L)
 {
	int i = 0, j = 0;
	DataType temp1, temp2;
	
	for(i = 0; i < L->size; i++)
	{
		for(j = 0; j < L->size - 1; j++)
		{
			ListGet(*L,   j  , &temp1);
			ListGet(*L, j + 1, &temp2);
			
			if(temp1.grade < temp2.grade) ListExchange(L, j, j+1);
		}
	}
 }
