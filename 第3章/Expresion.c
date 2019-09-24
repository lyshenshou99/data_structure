#include <ctype.h>						//����isdigit()����
#include <string.h>						//����isdigit()����
#include <stdlib.h>						//����exit()����
#include <stdio.h>

typedef int DataType;
#include "LinStack.h"					//������ʽ��ջ��

void PostExp(char str[])
//������ջ�����׺���ʽ��ֵ�����
{
	DataType x, x1, x2;
	int i;
	LSNode *s;

	StackInitiate(&s);

	for(i = 0; str[i] != '#'; i++)		//ѭ��ֱ������Ϊ'#'
	{
		if(isdigit(str[i]))					//chΪ��������
		{
			x = (int)(str[i] - 48);					//����ֵ������������
			StackPush(s, x);					//x��ջ
		}
		else		
		{
			StackPop(s, &x2);				//��ջ�ò�����
			StackPop(s, &x1);				//��ջ�ñ�������
			switch(str[i])
			{
				case '+': {x1 += x2; break;}
				case '-': {x1 -= x2; break;}
				case '*': {x1 *= x2; break;}
				case '/': 
				if(x2 == 0.0)
				{
					printf("����Ϊ0��!\n");
					exit(0);
				}
				else
				{
					x1 /= x2;
					break;
				}
			}
			StackPush(s, x1);					//��������ջ
		}
	}
	StackPop(s, &x);
	printf("��׺���ʽ������Ϊ: %d", x);
}

void main(void)
{
   char str[] = "3642/-5*+#";					
//   char str[] = "12+#";					

   PostExp(str);
}

