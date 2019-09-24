#include <stdio.h>
void Display(int n)
{
	int i;

	for(i = 1; i <= n; i++)
		printf("%d   ", n);
	printf("%\n");

	if(n > 0) Display(n - 1);			/*递归*/
	/*n<=0为递归出口，递归出口为空语句*/
}

void main(void)
{
	Display(4);
}
