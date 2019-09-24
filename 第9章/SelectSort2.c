#include <stdio.h>

typedef int KeyType;
typedef struct
{
	KeyType key;
} DataType;

#define MaxSize 100
#include "SeqList.h"

void SeleSort2(DataType a[], int n)
/*稳定的直接选择排序*/
{
	int i, j, k;
	DataType temp;

  	for(i = 0; i < n-1; i++)
	{
		k = i;
      	for(j = i + 1; j < n; j++)
			if(a[j].key < a[k].key)	k = j;

		if(k != i)
		{
			temp = a[k];
			for (j = k; j > i; j--) a[j] = a[j-1];
			a[i] = temp;
		}
	}
}

void main(void)
{
	DataType test[6]={64,5,7,89,6,24};
	int i, n = 6;
	SeqList myList;

	ListInitiate(&myList);
	for(i = 0; i < n; i++)
		ListInsert(&myList, i, test[i]);

	SeleSort2(myList.list, myList.size);

	for(i=0; i<n; i++)
		printf("%d   ", myList.list[i].key);
}
