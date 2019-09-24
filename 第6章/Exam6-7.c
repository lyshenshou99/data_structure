#include <stdio.h>

int Gcd(int n, int m)
{
	if(n < 0 || m < 0) 
	{
		printf("²ÎÊý´í£¡");
		return -1;
	}

	if(m == 0) return n;
	else if(m > n) return Gcd(m, n);
	else return Gcd(m, n % m);
}
void main(void)
{
	int y;

	y = Gcd(97, 5);
	printf("y = %d", y);
}