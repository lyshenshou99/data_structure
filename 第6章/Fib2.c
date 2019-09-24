#include <stdio.h>
long Fib2(int n)
{
	long int oneBack, twoBack, current;
	int i;

	if(n == 0 || n == 1) return n;
	else
	{
		oneBack = 1;
		twoBack = 0;
		for(i = 2; i <= n; i++)
		{
			current = oneBack + twoBack;
			twoBack = oneBack;
			oneBack = current;
		}
		return current;
	}
}

main(void)
{
	int i, f;

	for(i = 0; i < 10; i++)
	{
		f = Fib2(i);
		printf("%d     ", f);
	}
}