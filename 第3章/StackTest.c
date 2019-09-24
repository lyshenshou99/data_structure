#include <stdio.h>							/*该文件包含pringtf()等函数*/
#include <stdlib.h>
#define MaxStackSize  100						/*定义MaxSize为100*/
typedef int DataType;						/*定义DataType为int*/
#include "SeqStack.h"					

void main(void)
{
	SeqStack myStack;
	int i , x;

	StackInitiate(&myStack);					/*初始化*/
	for(i = 0; i < 10; i++)
		StackPush(myStack, i+1); 		/*入栈10个数据元素*/

	if(StackTop(myStack, &x) == 0) 		return;
	else printf("%d\n", x);
		
	printf("依次出栈的数据元素序列如下：\n");
	while(StackNotEmpty(myStack))
	{
		StackPop(&myStack, &x);  			/*出栈*/
		printf("%d    ", x);				/*显示数据元素*/
	}	
}
