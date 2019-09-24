#include <iostream.h>
#include <stdlib.h>

const MaxStackSize = 100;
#include "SeqStack.h"

//template <class T>
int ExpIsCorrect(char exp[], int n)
/*判断有n个字符的字符类型算术表达式exp是否配对正确*/
/*若配对正确则返回1，否则返回0*/
{
	SeqStack myStack;					/*定义链式堆栈*/
	int i;
	char x;

cout << "AAA   ";
	for(i = 0; i < n; i++)
	{
		cout << exp[i] << "   ";
		if((exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{'))
			myStack.Push(exp[i]);							/*入栈*/
//		else if(myStack.NotEmpty() && x = myStack.GetTop() )
//			x = myStack.Pop();
		else if(exp[i] == ')' && myStack.NotEmpty() 
			&& x = myStack.GetTop() && x == '(') 
			x = myStack.Pop(); 								/*出栈*/
		else if(exp[i] == ']' && myStack.NotEmpty() 
			&& x = myStack.GetTop() && x == '[')
			x = myStack.Pop(); 								/*出栈*/
		else if(exp[i] == '}' && myStack.NotEmpty() 
			&& x = myStack.GetTop() && x == '{')
			x = myStack.Pop(); 								/*出栈*/
		else
		{
			cout << "括号匹配不正确！" << endl;
			return 0;
		}
		cout << exp[i] << "   ";
	}

	if(myStack.NotEmpty())
	{
		cout << "括号匹配不正确！" << endl;
		return 0;
	}
	else
	{
		cout << "括号匹配正确！" << endl;
		return 1;
	}
}

void main(void)
{
	char a[] = "(())){[]}";		/*测试例子。注意：右括号多于左括号*/
	int  n = 9;
cout << "BBB   ";
	ExpIsCorrect(a, n);
cout << "CCC   ";
}

