#include <stdio.h>
#include <stdlib.h>

int Max(int a[], int n)
{
	int x;

	if(n <= 0)	exit(0);				/*参数出错退出*/

	if(n == 1) return a[n-1];			/*递归出口*/
	else 
	{
		x = Max(a, n-1);				/*递归求n-1个中的最大值*/
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