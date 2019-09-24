//4-13 �贮���þ�̬����洢�ṹ����д����ʵ���������ıȽ�Compare(S, T)��Ҫ��ȽϽ���д��ڡ����ں�С�����������
#include <stdio.h>
#define MaxSize 100

#include "SString.h"				/*������̬����Ĵ������ļ�*/

int Compare(String s, String t)
{
	int n = s.length, m = t.length, i, j, tag;

	i = 0; j = 0;
	while(i < n && j < m)
	{
		if(s.str[i] == t.str[j]) 			/*�����Ƚ���һ���ַ�*/
		{
			i++; j++;			
		}		
		else if(s.str[i] > t.str[i]) 
		{
			tag = 1;						/*˵��s>t���˳��Ƚ�*/
			return tag;
		}
		else
		{
			tag = -1;						/*˵��s<t���˳��Ƚ�*/
			return tag;
		}
	}

	if(n == m) tag = 0;			/*�������ַ��ȽϾ������tag=0*/
	else if(n > m) tag = 1;		/*����tֻ�ʹ�s��ǰm���ַ������s>t*/
	else if(n < m) tag = -1;	/*����sֻ�ʹ�t��ǰn���ַ������s<t*/
	return tag;					
}

void main(void)
{
	String myString1 = {"Data ", 5}, 
		 myString2 = {"Structure", 9};
	int result;

	result = Compare(myString2, myString1);
	printf("result = %d", result);
}
