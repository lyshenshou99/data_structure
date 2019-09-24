#include <stdio.h>
typedef float DataType;

DataType Max3(DataType x1, DataType x2)
{
	if(x1 >= x2) return x1;
	else return x2;
}

void main(void)
{
	DataType t1 = 5.1, t2 = 8.8, max;

	max = Max3(t1, t2);
	printf("Max = %f\n", max);

	max = Max3(t2, t1);
	printf("Max = %f\n", max);
}
