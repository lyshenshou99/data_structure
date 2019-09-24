#include <stdio.h>

typedef int KeyType;
typedef struct
{
	KeyType key;
} DataType;

void ShellSort(DataType a[], int n, int d[], int numOfD)
/*��ϣ�����򷨶Լ�¼a[0]--a[n-1]����d[0]--d[numOfD-1]Ϊ����ֵ*/
{
	int i, j, k, m, span;
	DataType temp;

	for(m = 0; m < numOfD; m++)					/*��numOfD��ѭ��*/
	{
		span = d[m];								/*ȡ���ε�����ֵ*/
		for(k = 0; k < span; k++)						/*��span��С��*/
		{
			/*ÿ��С���ڰ�ֱ�Ӳ����㷨��������ֻ��ÿ�β�����1������span*/
			for(i = k; i < n-span; i = i+span)			
			{
				temp = a[i+span];
				j = i;
				while(j > -1 && temp.key <= a[j].key)
				{
					a[j+span] = a[j];
					j = j-span;
				}
				a[j+span] = temp;
			}
		}
	}
}

void main(void)
{
	DataType test[]={65,34,25,87,12,38,56,46,14,77,92,23};
	int i, n = 12, d[] = {6, 3, 1}, numOfD = 3;

	ShellSort (test, n, d, numOfD);

	for(i=0; i<n; i++)
	printf("%d   ", test[i].key);
}
