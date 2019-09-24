#include <stdio.h>

typedef int KeyType;
typedef struct
{
	KeyType key;
} DataType;

void CreatHeap(DataType a[], int n, int h)
{
	int i,j,flag;
	DataType temp;

	i = h;		        /* iΪҪ���ѵĶ�����������±�*/		
	j = 2*i+1;			/* jΪi�����ӽ����±�*/
	temp = a[i];
	flag = 0;

	/*�����Һ�����ֵ�ϴ����ظ�����ɸѡ*/
	while(j < n && flag != 1)
	{
		/*Ѱ�����Һ��ӽ���еĽϴ���,jΪ���±�*/
		if(j < n-1 && a[j].key < a[j+1].key) j++;

		if(temp.key > a[j].key)	/*a[i].key>a[j].key*/
			flag=1;				/*��ǽ���ɸѡ����*/
		else					/*�����a[j]����*/
		{
			a[i] = a[j];
			i = j;
			j = 2*i+1;
		}
	}

	a[i] = temp;				/*�������a[i]��������a[j]*/
}

void InitCreatHeap(DataType a[], int n)		/*��ʼ����������*/
{
	int i;

	for(i = (n-1)/2; i>=0; i--)
		CreatHeap(a, n, i);
}

void HeapSort (DataType a[], int n)
/*�ö����򷨶Լ�¼a[0]--a[n-1]����*/
{
	int i;
	DataType temp;
   
	InitCreatHeap(a, n);					/*��ʼ����������*/

	for(i = n-1; i > 0; i--)			
	{
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		CreatHeap(a, i, 0);
	}
}

void main(void)
{
	DataType test[]={10,50,32,5,76,16,9,40,88};
	int i, n = 9;

	HeapSort(test,n);

	for(i=0; i<n; i++)
	printf("%d   ", test[i].key);
}
