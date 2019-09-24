#include <stdio.h>
#include <malloc.h>

typedef int KeyType;
typedef struct
{
	KeyType key;
} DataType;

#include "LinQueue.h"
void RadixSort(DataType a[], int n, int m, int d)
/*对数据元素a[0]--a[n-1]进行关键字为m位d进制整型数值的基数排序*/
/*桶采用链式队列结构*/
{
	int i, j, k, power = 1;
	LQueue *tub;

	tub = (LQueue *)malloc(sizeof(LQueue )* d);
	for(i = 0; i < d; i++)
		QueueInitiate(&tub[i]);

	//进行m次放和收
	for(i = 0; i < m; i++)
	{
		if(i == 0) power = 1;
		else power = power *d;

		//将数据元素按关键字第k位的大小放到相应的队列中
		for(j = 0; j < n; j++)
		{
			k = a[j].key /power - (a[j].key /(power * d)) * d;
			QueueAppend(&tub[k], a[j]);
		}

		//顺序回收各队列中的数据元素
		for(j = 0, k = 0; j < d; j++)
			while(QueueNotEmpty(tub[j]) != 0)
			{
				 QueueDelete(&tub[j], &a[k]);
				 k++;
			}
	}
}

void main(void)
{
	DataType test[]={710, 342, 45, 686, 6, 841, 429, 134, 68, 246};
	int i, n = 10, m = 3, d = 10;
	
	RadixSort(test, n, m, d);
	for(i = 0; i < n; i++)
		printf("%d   ", test[i].key);
}
