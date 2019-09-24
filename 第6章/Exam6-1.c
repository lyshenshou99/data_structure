#include <stdio.h>
long int fact(int n)
{
	int x;
	long int y;
	
	if(n < 0)
	{
		printf("²ÎÊý´í£¡");
		return -1;
	}

	if(n == 0) return 1;
	else
	{
		x = n - 1;
		y = fact(x);
		return n * y;
	}
}

main(void)
{
	int n = 3;
	long int fn;

	fn = fact(3);
	printf("%d", fn);
}