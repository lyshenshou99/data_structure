#include<stdio.h>
#include<string.h>

int a[] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //给出的数组
int size = sizeof(a) / sizeof(int);
int sum = 10, k = 3;      //计算的和 要求的个数

void Print(bool* x)
{
    for(int i = 0; i < size; i++) 
	{
        if(x[i] == 1)
		{
			printf("%d", x[i]);
		}
    }
}

//x[]为最终解，i为考察第x[i]是否加入，has表示当前的和
void EnumNumber(bool* x, int i, int has, int step) 
{
    if(i >= size) return;
	if(step >= k) return;
	
    if(has + a[i] == sum && step == k) 
	{
        x[i] = true;
        Print(x);
        x[i] = false;
    }
	
    x[i] = true;
    EnumNumber(x, i + 1, has + a[i], step + 1);
	
    x[i] = false;
    EnumNumber(x, i + 1, has, step + 1);
}

int main() 
{
    bool x[size] = {};
	
    memset(x, 0, size);

    EnumNumber(x, 0, 0, 0);

    return 0;
}
