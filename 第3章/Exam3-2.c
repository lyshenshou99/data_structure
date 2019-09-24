#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxStackSize  100
typedef char DataType;
#include "SeqStack.h"

void ExpIsCorrect(char exp[], int n)
//判断有n个字符的字符串exp左右括号是否配对正确
{
	SeqStack myStack;					//定义链式堆栈
	int i;
	char c;

	StackInitiate(&myStack);
	for(i = 0; i < n; i++)
	{
		if((exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{'))
			StackPush(&myStack, exp[i]);							//入栈

		else if(exp[i] == ')' && StackNotEmpty(myStack) 
			&& StackTop(myStack, &c) && c == '(') 
			StackPop(&myStack, &c); 								//出栈
		else if(exp[i] == ')' && StackNotEmpty(myStack) 
			&& StackTop(myStack, &c) && c != '(') 
			{
				printf("左右括号配对次序不正确！\n");
				return;
			}

		else if(exp[i] == ']' && StackNotEmpty(myStack) 
			&& StackTop(myStack, &c) && c == '[')
			StackPop(&myStack, &c); 								//出栈
		else if(exp[i] == ']' && StackNotEmpty(myStack) 
			&& StackTop(myStack, &c) && c != '[')
			{
				printf("左右括号配对次序不正确！\n");
				return;
			}

		else if(exp[i] == '}' && StackNotEmpty(myStack) 
			&& StackTop(myStack, &c) && c == '{')
			StackPop(&myStack, &c); 								//出栈
		else if(exp[i] == '}' && StackNotEmpty(myStack) 
			&& StackTop(myStack, &c) && c != '{')
			{
				printf("左右括号配对次序不正确！\n");
				return;
			}

		else if(((exp[i] == ')') || (exp[i] == ']') || (exp[i] == '}')) 
				&& !StackNotEmpty(myStack))
		{
			printf("右括号多于左括号！\n");
			return;
		}
	}

	if(StackNotEmpty(myStack))
		printf("左括号多于右括号！\n");
	else
		printf("左右括号匹配正确！\n");
}

void main(void)
{
	char a[] = "(())abc{[)(]}";		//测试例子1。左右括号配对次序不正确
	char b[] = "(()))abc{[]}";		//测试例子2。右括号多于左括号
	char c[] = "(()()abc{[]}";		//测试例子3。左括号多于右括号
	char d[] = "(())abc{[]}";		//测试例子4。左右括号匹配正确
	int n1 = strlen(a);
	int n2 = strlen(b);
	int n3 = strlen(c);
	int n4 = strlen(d);

	ExpIsCorrect(a, n1);
	ExpIsCorrect(b, n2);
	ExpIsCorrect(c, n3);
	ExpIsCorrect(d, n4);
}

