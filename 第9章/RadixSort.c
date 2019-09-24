#include <stdio.h>
#include <malloc.h>

typedef int KeyType;
typedef struct
{
	KeyType key;
} DataType;

#include "LinQueue.h"
void RadixSort(DataType a[], int n, int m, int d)
/*������Ԫ��a[0]--a[n-1]���йؼ���Ϊmλd����������ֵ�Ļ�������*/
/*Ͱ������ʽ���нṹ*/
{
	int i, j, k, power = 1;
	LQueue *tub;

	tub = (LQueue *)malloc(sizeof(LQueue )* d);
	for(i = 0; i < d; i++)
		QueueInitiate(&tub[i]);

	//����m�ηź���
	for(i = 0; i < m; i++)
	{
		if(i == 0) power = 1;
		else power = power *d;

		//������Ԫ�ذ��ؼ��ֵ�kλ�Ĵ�С�ŵ���Ӧ�Ķ�����
		for(j = 0; j < n; j++)
		{
			k = a[j].key /power - (a[j].key /(power * d)) * d;
			QueueAppend(&tub[k], a[j]);
		}

		//˳����ո������е�����Ԫ��
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
