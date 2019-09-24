#include <stdio.h>
#include <malloc.h>

typedef int KeyType;
typedef struct
{
	KeyType key;
} DataType;

void Merge(DataType a[], int n, DataType swap[], int k)
/*kΪ����������ĳ��ȣ�һ�ζ�·�鲢���������������д�������swap��*/
{
	int m = 0, u1,l2,i,j,u2;

	int l1 = 0;									/*��һ�������������½�Ϊ0*/	
	while(l1+k <= n-1)
	{
		l2 = l1 + k;							/*����ڶ��������������½�*/
		u1 = l2 - 1;							/*�����һ�������������Ͻ�*/
		u2 = (l2+k-1 <= n-1)? l2+k-1: n-1;			/*����ڶ��������������Ͻ�*/

		/*��������������ϲ�*/
		for(i = l1, j = l2; i <= u1 && j <= u2; m++)	
		{
			if(a[i].key <= a[j].key)
			{
				swap[m] = a[i];
				i++;
			}
			else
			{
				swap[m]=a[j];
				j++;
			}
		}

		/*������2�ѹ鲢�꣬��������1��ʣ���Ԫ�ش�ŵ�����swap��*/
		while(i <= u1)
		{
			swap[m] = a[i];
			m++;
			i++;
		}

		/*������1�ѹ鲢�꣬��������2��ʣ���Ԫ�ش�ŵ�����swap��*/
		while(j <= u2)
		{
			swap[m] = a[j];
			m++;
			j++;
		}

		l1 = u2 + 1;
	}

	/*��ԭʼ������ֻ��һ�������Ԫ��˳���ŵ�����swap��*/
	for(i = l1; i < n; i++, m++) swap[m] = a[i];
}

void MergeSort(DataType a[], int n)
{
	int i, k = 1;									/*�鲢���ȴ�1��ʼ*/
	DataType *swap;
		
	swap = (DataType *)malloc(sizeof(DataType)*n);	/*���붯̬����ռ�*/

	while(k < n)
	{
		Merge(a, n, swap, k);
		for(i = 0; i < n; i++)			/*������Ԫ�ش�����swap�Ż�a��*/
			a[i] = swap[i]; 
		k = 2 * k; 									/*�鲢���ȼӱ�*/
	}
	free(swap);									/*�ͷŶ�̬����*/
}

void main(void)
{
	DataType test[]={10,50,32,5,76,16,9,40,88};
	int i, n = 9;

	MergeSort(test, n);

	for(i=0; i<n; i++)
	printf("%d   ", test[i].key);
}
