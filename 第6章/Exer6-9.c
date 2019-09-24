#include <stdio.h>

int Sum(int a[], int n)
{

	if (n == 1) return a[n-1];
	else return n + Sum(a, n- 1);
}

void main(void)
{
	int a[] = {1,2,3,4,5,6,7,8}, n = 8, y;

	y = Sum(a, n);
	printf("y = %d\n", y);
}