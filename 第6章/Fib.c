#include <stdio.h>
long Fib(int n)
{
	if(n == 0 || n == 1) return n;		//�ݹ����
	else return Fib(n-1) + Fib(n-2);	//�ݹ����
}

main(void)
{
	int i, f;

	for(i = 0; i < 10; i++)
	{
		f = Fib(i);
		printf("%d     ", f);
	}
}