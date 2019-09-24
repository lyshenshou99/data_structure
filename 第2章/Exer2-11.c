#include <stdio.h>
#define MaxSize  100
typedef int DataType;
#include "SeqList.h"

void show(SeqList L)
{
	int i;
	for(i = 0; i < L.size; i++)
		printf("%d   ", L.list[i]);
}

void main(void)
{
	SeqList myList;
	int a[] = {3, 8, 2, 4, 1, 5, 7};
	int i, x;
	
	ListInitiate(&myList);
	for(i = 0; i < 7; i++)
		ListInsert(&myList, i, a[i]);

	show(myList);	
}
