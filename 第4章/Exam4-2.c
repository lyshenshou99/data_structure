//4-13 �贮���þ�̬����洢�ṹ����д����ʵ���������ıȽ�Compare(S, T)��Ҫ��ȽϽ���д��ڡ����ں�С�����������
#include <stdio.h>
#define MaxSize 100

#include "SString.h"				/*������̬����Ĵ������ļ�*/

void main(void)
{
	String myString1 = {"Data ", 5}, 
		 myString2 = {"Structure", 9};
	int i;

	Insert(&myString2, 0, myString1);					

	for(i = 0; i < myString2.length; i++)
		printf("%c", myString2.str[i]);
}
