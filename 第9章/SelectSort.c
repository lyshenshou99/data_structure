#include <stdio.h>

typedef int KeyType;
typedef struct
{
	KeyType key;
} DataType;

void SelectSort(DataType a[], int n)
/*��ֱ��ѡ�����򷨶�a[0]--a[n-1]����*/
{
	int i, j, small;
	DataType temp;

	for(i = 0; i < n-1; i++)				/*���ѡȡ��0������n-2������Ԫ��*/
	{
		small = i;						/*���i������Ԫ�عؼ�����С*/
		for(j = i+1; j < n; j++)			/*Ѱ�ҹؼ�����С������Ԫ��*/
			if(a[j].key < a[small].key) small=j;/*��ס��С����Ԫ�ص��±�*/

		if(small != i)				/*����С����Ԫ�ص��±겻Ϊiʱ����λ��*/
		{
			temp = a[i];
			a[i] = a[small];
			a[small] = temp;
		}
	}
}

void main(void)
{
	DataType test[6]={64,5,7,89,6,24};
	int i, n = 6;

	SelectSort(test,n);

	for(i=0; i<n; i++)
	printf("%d   ", test[i].key);
}
