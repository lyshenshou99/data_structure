#include <stdio.h>

int Gcd2(int n, int m)
{
	int tn, tm, temp;
	if(n < 0 || m < 0)
	{
		printf("参数错！");
		return -1;
	}

	
	if(m > n) 			/*交换参数位置*/
	{
		tn = m;
		tm = n;
	}
	else 				/*不交换参数位置*/
	{
		tn = n;
		tm = m;
	}
	while(tm != 0)		/*用循环结构替代递归*/
	{
		temp = tn;
		tn = tm;
		tm = temp % tm;
	}
	return tn;			/*返回最大公约数*/
}

void main(void)
{
	int y;

	y = Gcd2(30, 4);
	printf("y = %d", y);
}