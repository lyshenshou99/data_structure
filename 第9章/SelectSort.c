#include <stdio.h>

typedef int KeyType;
typedef struct
{
	KeyType key;
} DataType;

void SelectSort(DataType a[], int n)
/*用直接选择排序法对a[0]--a[n-1]排序*/
{
	int i, j, small;
	DataType temp;

	for(i = 0; i < n-1; i++)				/*逐个选取第0个到第n-2个数据元素*/
	{
		small = i;						/*设第i个数据元素关键字最小*/
		for(j = i+1; j < n; j++)			/*寻找关键字最小的数据元素*/
			if(a[j].key < a[small].key) small=j;/*记住最小数据元素的下标*/

		if(small != i)				/*当最小数据元素的下标不为i时交换位置*/
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
