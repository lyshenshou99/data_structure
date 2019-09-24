#include <stdio.h>
#define MaxSize  100
typedef int DataType;
#include "SeqList.h"

int ListMoreDataDelete(SeqList *L, DataType x)
{
	int i, j;
	int tag = 0;							/*初始删除标记置为0*/

	for(i = 0; i < L->size; i++)			/*元素x的全部删除*/	
	{
		if(x == L->list[i])					/*寻找到元素x*/
		{
			for(j = i; j < L->size; j++)			/*依次前移*/
				L->list[j] = L->list[j+1];
			
			L->size--;								/*元素个数减1*/
			i--;			/*保证两个相临的元素均为x时正确删除*/
			tag = 1;							/*设置删除成功标记*/
		}
	}

	return tag;
}

void main(void)
{
	SeqList myList;
	int a[] = {3, 8, 2, 1, 5, 5,7};
	int i, x = 5;
	
	ListInitiate(&myList);
	for(i = 0; i < 7; i++)
		ListInsert(&myList, i, a[i]);

	ListMoreDataDelete(&myList, x);

	for(i = 0; i < ListLength(myList); i++)			/*依次输出顺序表中的数据*/
	{
		ListGet(myList, i, &x);
		printf("%d   ", x);							/*显示*/
	}	
}

