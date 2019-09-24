#include <ctype.h>						//包含isdigit()函数
#include <string.h>						//包含isdigit()函数
#include <stdlib.h>						//包含exit()函数
#include <stdio.h>

typedef int DataType;
#include "LinStack.h"					//包含链式堆栈类

void PostExp(char str[])
//借助堆栈计算后缀表达式的值后输出
{
	DataType x, x1, x2;
	int i;
	LSNode *s;

	StackInitiate(&s);

	for(i = 0; str[i] != '#'; i++)		//循环直到输入为'#'
	{
		if(isdigit(str[i]))					//ch为数字类型
		{
			x = (int)(str[i] - 48);					//按数值类型重新输入
			StackPush(s, x);					//x入栈
		}
		else		
		{
			StackPop(s, &x2);				//退栈得操作数
			StackPop(s, &x1);				//退栈得被操作数
			switch(str[i])
			{
				case '+': {x1 += x2; break;}
				case '-': {x1 -= x2; break;}
				case '*': {x1 *= x2; break;}
				case '/': 
				if(x2 == 0.0)
				{
					printf("除数为0错!\n");
					exit(0);
				}
				else
				{
					x1 /= x2;
					break;
				}
			}
			StackPush(s, x1);					//运算结果入栈
		}
	}
	StackPop(s, &x);
	printf("后缀表达式计算结果为: %d", x);
}

void main(void)
{
   char str[] = "3642/-5*+#";					
//   char str[] = "12+#";					

   PostExp(str);
}

