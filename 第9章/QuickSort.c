#include <stdio.h>

typedef int KeyType;
typedef struct
{
	KeyType key;
} DataType;

void QuickSort(DataType a[], int low, int high)
/*用递归方法对数据元素a[low]--a[high]进行快速排序*/
{
	int i = low, j = high;
	DataType temp = a[low];	/*取第一个数据元素为进行调整的标准数据元素*/

	while(i < j)
	{
		while(i < j && temp.key <= a[j].key) j--;		/*在数组的右端扫描*/
		if(i < j)
		{
			a[i] = a[j];
			i++;
		}

		while(i < j && a[i].key < temp.key) i++;		/*在数组的左端扫描*/
		if(i < j)
		{
			a[j] = a[i];
			j--;
		}
	}
	a[i] = temp;

	if(low < i) QuickSort(a, low, i-1);		/*对左端子集合元素进行递归快速排序*/
	if(i < high) QuickSort(a, j+1, high);	/*对右端子集合元素进行递归快速排序*/
}

void main(void)
{
	DataType test[]={10,50,32,5,76,16,9,40,88};
	int i, n = 9;

	QuickSort(test,0, n-1);

	for(i=0; i<n; i++)
	printf("%d   ", test[i].key);
}
