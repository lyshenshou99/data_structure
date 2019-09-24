#include <stdio.h>

typedef int KeyType;
typedef struct
{
	KeyType key;
} DataType;

void BubbleSort(DataType a[], int n)
{
	int i, j, flag = 1;
	DataType temp;

	for(i = 1; i < n && flag == 1; i++)
	{
		flag = 0;
		for(j = 0; j < n-i; j++)
		{
			if(a[j].key > a[j+1].key)
			{
				flag = 1;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

void main(void)
{
	DataType test[]={10,50,32,5,76,16,9,40,88};
	int i, n = 9;

	BubbleSort(test,n);

	for(i=0; i<n; i++)
	printf("%d   ", test[i].key);
}
