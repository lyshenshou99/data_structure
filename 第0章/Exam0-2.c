#include <stdio.h>

void Max2(int x1, int x2, int x3, int *y1, int *y2)
/*输出参数y1和y2设计为指针类型*/
{
	if(x1 >= x2 && x1 >= x3)
	{
		*y1 = x1;
		if(x2 >= x3) *y2 = x2;
		else *y2 = x3;
	}

	if(x1 >= x2 && x1 < x3)
	{
		*y1 = x3;
		if(x1 >= x2) *y2 = x1;
		else *y2 = x2;
	}

	if(x1 < x2 && x2 >= x3)
	{
		*y1 = x2;
		if(x1 >= x3) *y2 = x1;
		else *y2 = x3;
	}

	if(x1 < x2 && x2 < x3)
	{
		*y1 = x3;
		if(x1 >= x2) *y2 = x1;
		else *y2 = x2;
	}
}

void main(void)
{
	int v1 = 5, v2 = 9, v3 = 7, f1, f2;

	Max2(v1, v2, v3, &f1, &f2);	/*&f1表示f1的地址，为指针类型*/
	printf("f1 = %d   f2 = %d\n", f1, f2);
}
