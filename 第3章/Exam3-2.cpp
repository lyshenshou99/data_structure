#include <iostream.h>
#include <stdlib.h>

const MaxStackSize = 100;
#include "SeqStack.h"

//template <class T>
int ExpIsCorrect(char exp[], int n)
/*�ж���n���ַ����ַ������������ʽexp�Ƿ������ȷ*/
/*�������ȷ�򷵻�1�����򷵻�0*/
{
	SeqStack myStack;					/*������ʽ��ջ*/
	int i;
	char x;

cout << "AAA   ";
	for(i = 0; i < n; i++)
	{
		cout << exp[i] << "   ";
		if((exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{'))
			myStack.Push(exp[i]);							/*��ջ*/
//		else if(myStack.NotEmpty() && x = myStack.GetTop() )
//			x = myStack.Pop();
		else if(exp[i] == ')' && myStack.NotEmpty() 
			&& x = myStack.GetTop() && x == '(') 
			x = myStack.Pop(); 								/*��ջ*/
		else if(exp[i] == ']' && myStack.NotEmpty() 
			&& x = myStack.GetTop() && x == '[')
			x = myStack.Pop(); 								/*��ջ*/
		else if(exp[i] == '}' && myStack.NotEmpty() 
			&& x = myStack.GetTop() && x == '{')
			x = myStack.Pop(); 								/*��ջ*/
		else
		{
			cout << "����ƥ�䲻��ȷ��" << endl;
			return 0;
		}
		cout << exp[i] << "   ";
	}

	if(myStack.NotEmpty())
	{
		cout << "����ƥ�䲻��ȷ��" << endl;
		return 0;
	}
	else
	{
		cout << "����ƥ����ȷ��" << endl;
		return 1;
	}
}

void main(void)
{
	char a[] = "(())){[]}";		/*�������ӡ�ע�⣺�����Ŷ���������*/
	int  n = 9;
cout << "BBB   ";
	ExpIsCorrect(a, n);
cout << "CCC   ";
}

