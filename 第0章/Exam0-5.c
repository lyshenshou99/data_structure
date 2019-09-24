#include <stdio.h>							/*该文件包含pringtf()等函数*/
#define MaxSize  100						/*定义MaxSize为100*/
typedef int DataType;						/*定义DataType为int*/
#include "SeqList.h"						/*包含线性表文件*/

void main(void)
{
	SeqList myList;
	int i , x, n = 10, a[10] = {1,2,3,4,5,6,7,8,9,10};

	ListInitiate(&myList);					/*初始化*/
	for(i = 0; i < n; i++)
	{
		if(ListInsert(&myList, i, a[i]) == 0) 	/*插入10个数据元素*/
		{
			printf("错误! \n");
			return;
		}
	}
	
	n = ListLength(myList);
	for(i = 0; i < n; i++)
	{
		if(ListGet(myList, i, &x) == 0) 		/*取元素*/
		{
			printf("错误! \n");
			return;
		}
		else printf("%d    ", x);			/*显示数据元素*/
	}	
}
