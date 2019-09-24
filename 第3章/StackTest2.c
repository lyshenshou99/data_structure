#include <stdio.h>							/*该文件包含pringtf()函数*/
#include <stdlib.h>							/*该文件包含exit()函数*/
#include <malloc.h>
typedef int DataType;						/*定义DataType为int*/
#include "LinStack.h"

void main(void)
{
	LSNode *head;
	int i , x;

	StackInitiate(&head);					/*初始化*/
	for(i = 0; i < 10; i++)
	{
		if(StackPush(head, i+1) == 0) 		/*入栈10个数据元素*/
		{
			printf("错误! \n");
			return;
		}
	}
	
	if(StackTop(head, &x) == 0) 		/*取栈顶数据元素*/
	{
		printf("错误! \n");
		return;
	}
	else
		printf("%d\n", x);
		
	printf("依次出栈的数据元素序列如下：\n");
	while(StackNotEmpty(head))
	{
		StackPop(head, &x); 			/*出栈*/
		printf("%d    ", x);			/*显示数据元素*/
	}	
}
