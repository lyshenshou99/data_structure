#include <stdio.h>
#include <stdlib.h>

int Max(int a[], int n)
{
	int x;

	if(n <= 0)	exit(0);				/*���������˳�*/

	if(n == 1) return a[n-1];			/*�ݹ����*/
	else 
	{
		x = Max(a, n-1);				/*�ݹ���n-1���е����ֵ*/
		if(x > a[n-1]) return x;
		else return a[n-1]; 
	}
}

void main(void)
{
	int a[] = {1,2,3,4,5,6,7,8}, n = 8, y;

	y = Max(a, n);
	printf("y = %d\n", y);
}