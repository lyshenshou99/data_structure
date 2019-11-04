#include<stdio.h>
#include<string.h>

#define bool int
#define true  1
#define false 0

int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //给出的数组
int size = sizeof(a) / sizeof(int);
int sum = 23, k = 3;      //计算的和 要求的个数
int i = 0;

void Print(bool* x)
{
    for(i = 0; i < size; i++) 
	{
        if(x[i] == 1)
		{
			printf("%-4d", a[i]);
		}
    }
    printf("\n");
}

//x[]为最终解，i为考察a[i]是否加入，has表示当前的和
void EnumNumber(bool* x, int i, int has, int step) 
{
    if(step > k) return;
	if(i >= size) return;
	if(has + a[i] > sum) return;
	
    if((has + a[i] == sum) && (step == k)) 
	{
        x[i] = true;
        Print(x);
        x[i] = false;
    }
	
    x[i] = true;
    EnumNumber(x, i + 1, has + a[i], step + 1);
	
    x[i] = false;
    EnumNumber(x, i + 1, has, step);
}

int main() 
{
    bool x[size];
	
    memset(x, 0, size);

    EnumNumber(x, 0, 0, 0);

    return 0;
}
