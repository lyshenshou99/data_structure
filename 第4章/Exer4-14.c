#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include"DString.h"					/*������̬����Ĵ������ļ�*/

int Compare(DString s, DString t)
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
	DString	myString1, myString2, myString3;
	int i, max1 = 10, max2 = 20, max3 = 10;
		
	/*���Գ�ʼ������*/
	Initiate(&myString1, max1, "Data ");
	Initiate(&myString2, max2, "Structure");
	Initiate(&myString3, max3, "");

	/*���Բ��뺯��*/
	Insert(&myString2, 0, myString1);
	for(i = 0; i < myString2.length; i++)
		printf("%c", myString2.str[i]);
	printf("\n");

	/*����ɾ������*/
	Delete(&myString2, 0, 5);
	for(i = 0; i < myString2.length; i++)
		printf("%c", myString2.str[i]);
	printf("\n");

	/*����ȡ�Ӵ�����*/
	SubString(&myString2, 0, 5, &myString3);
	for(i = 0; i < myString3.length; i++)
		printf("%c", myString3.str[i]);
	printf("\n");

	/*���Գ�������*/
	Destroy(&myString1);
	Destroy(&myString2);
}
