#include <stdio.h>							/*���ļ�����pringtf()�Ⱥ���*/
#include <stdlib.h>
#define MaxStackSize  100						/*����MaxSizeΪ100*/
typedef int DataType;						/*����DataTypeΪint*/
#include "SeqStack.h"					

void main(void)
{
	SeqStack myStack;
	int i , x;

	StackInitiate(&myStack);					/*��ʼ��*/
	for(i = 0; i < 10; i++)
		StackPush(myStack, i+1); 		/*��ջ10������Ԫ��*/

	if(StackTop(myStack, &x) == 0) 		return;
	else printf("%d\n", x);
		
	printf("���γ�ջ������Ԫ���������£�\n");
	while(StackNotEmpty(myStack))
	{
		StackPop(&myStack, &x);  			/*��ջ*/
		printf("%d    ", x);				/*��ʾ����Ԫ��*/
	}	
}
