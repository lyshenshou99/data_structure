#include <stdio.h>
#include <malloc.h>

typedef int KeyType;
typedef struct
{
	KeyType key;
} DataType;

void Merge(DataType a[], int n, DataType swap[], int k)
/*k为有序子数组的长度，一次二路归并排序后的有序子序列存于数组swap中*/
{
	int m = 0, u1,l2,i,j,u2;

	int l1 = 0;									/*第一个有序子数组下界为0*/	
	while(l1+k <= n-1)
	{
		l2 = l1 + k;							/*计算第二个有序子数组下界*/
		u1 = l2 - 1;							/*计算第一个有序子数组上界*/
		u2 = (l2+k-1 <= n-1)? l2+k-1: n-1;			/*计算第二个有序子数组上界*/

		/*两个有序子数组合并*/
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

		/*子数组2已归并完，将子数组1中剩余的元素存放到数组swap中*/
		while(i <= u1)
		{
			swap[m] = a[i];
			m++;
			i++;
		}

		/*子数组1已归并完，将子数组2中剩余的元素存放到数组swap中*/
		while(j <= u2)
		{
			swap[m] = a[j];
			m++;
			j++;
		}

		l1 = u2 + 1;
	}

	/*将原始数组中只够一组的数据元素顺序存放到数组swap中*/
	for(i = l1; i < n; i++, m++) swap[m] = a[i];
}

void MergeSort(DataType a[], int n)
{
	int i, k = 1;									/*归并长度从1开始*/
	DataType *swap;
		
	swap = (DataType *)malloc(sizeof(DataType)*n);	/*申请动态数组空间*/

	while(k < n)
	{
		Merge(a, n, swap, k);
		for(i = 0; i < n; i++)			/*将数据元素从数组swap放回a中*/
			a[i] = swap[i]; 
		k = 2 * k; 									/*归并长度加倍*/
	}
	free(swap);									/*释放动态数组*/
}

void main(void)
{
	DataType test[]={10,50,32,5,76,16,9,40,88};
	int i, n = 9;

	MergeSort(test, n);

	for(i=0; i<n; i++)
	printf("%d   ", test[i].key);
}
