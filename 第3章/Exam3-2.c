#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxStackSize  100
typedef char DataType;
#include "SeqStack.h"

void ExpIsCorrect(char exp[], int n)
//�ж���n���ַ����ַ���exp���������Ƿ������ȷ
{
	SeqStack myStack;					//������ʽ��ջ
	int i;
	char c;

	StackInitiate(&myStack);
	for(i = 0; i < n; i++)
	{
		if((exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{'))
			StackPush(&myStack, exp[i]);							//��ջ

		else if(exp[i] == ')' && StackNotEmpty(myStack) 
			&& StackTop(myStack, &c) && c == '(') 
			StackPop(&myStack, &c); 								//��ջ
		else if(exp[i] == ')' && StackNotEmpty(myStack) 
			&& StackTop(myStack, &c) && c != '(') 
			{
				printf("����������Դ�����ȷ��\n");
				return;
			}

		else if(exp[i] == ']' && StackNotEmpty(myStack) 
			&& StackTop(myStack, &c) && c == '[')
			StackPop(&myStack, &c); 								//��ջ
		else if(exp[i] == ']' && StackNotEmpty(myStack) 
			&& StackTop(myStack, &c) && c != '[')
			{
				printf("����������Դ�����ȷ��\n");
				return;
			}

		else if(exp[i] == '}' && StackNotEmpty(myStack) 
			&& StackTop(myStack, &c) && c == '{')
			StackPop(&myStack, &c); 								//��ջ
		else if(exp[i] == '}' && StackNotEmpty(myStack) 
			&& StackTop(myStack, &c) && c != '{')
			{
				printf("����������Դ�����ȷ��\n");
				return;
			}

		else if(((exp[i] == ')') || (exp[i] == ']') || (exp[i] == '}')) 
				&& !StackNotEmpty(myStack))
		{
			printf("�����Ŷ��������ţ�\n");
			return;
		}
	}

	if(StackNotEmpty(myStack))
		printf("�����Ŷ��������ţ�\n");
	else
		printf("��������ƥ����ȷ��\n");
}

void main(void)
{
	char a[] = "(())abc{[)(]}";		//��������1������������Դ�����ȷ
	char b[] = "(()))abc{[]}";		//��������2�������Ŷ���������
	char c[] = "(()()abc{[]}";		//��������3�������Ŷ���������
	char d[] = "(())abc{[]}";		//��������4����������ƥ����ȷ
	int n1 = strlen(a);
	int n2 = strlen(b);
	int n3 = strlen(c);
	int n4 = strlen(d);

	ExpIsCorrect(a, n1);
	ExpIsCorrect(b, n2);
	ExpIsCorrect(c, n3);
	ExpIsCorrect(d, n4);
}

