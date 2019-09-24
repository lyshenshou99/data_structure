#include <stdio.h>

typedef int KeyType;
typedef struct
{
	KeyType key;
} DataType;

void QuickSort(DataType a[], int low, int high)
/*�õݹ鷽��������Ԫ��a[low]--a[high]���п�������*/
{
	int i = low, j = high;
	DataType temp = a[low];	/*ȡ��һ������Ԫ��Ϊ���е����ı�׼����Ԫ��*/

	while(i < j)
	{
		while(i < j && temp.key <= a[j].key) j--;		/*��������Ҷ�ɨ��*/
		if(i < j)
		{
			a[i] = a[j];
			i++;
		}

		while(i < j && a[i].key < temp.key) i++;		/*����������ɨ��*/
		if(i < j)
		{
			a[j] = a[i];
			j--;
		}
	}
	a[i] = temp;

	if(low < i) QuickSort(a, low, i-1);		/*������Ӽ���Ԫ�ؽ��еݹ��������*/
	if(i < high) QuickSort(a, j+1, high);	/*���Ҷ��Ӽ���Ԫ�ؽ��еݹ��������*/
}

void main(void)
{
	DataType test[]={10,50,32,5,76,16,9,40,88};
	int i, n = 9;

	QuickSort(test,0, n-1);

	for(i=0; i<n; i++)
	printf("%d   ", test[i].key);
}
