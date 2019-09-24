#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include"DString.h"					/*包含动态数组的串操作文件*/

int Compare(DString s, DString t)
{
	int n = s.length, m = t.length, i, j, tag;

	i = 0; j = 0;
	while(i < n && j < m)
	{
		if(s.str[i] == t.str[j]) 			/*继续比较下一个字符*/
		{
			i++; j++;			
		}		
		else if(s.str[i] > t.str[i]) 
		{
			tag = 1;						/*说明s>t，退出比较*/
			return tag;
		}
		else
		{
			tag = -1;						/*说明s<t，退出比较*/
			return tag;
		}
	}

	if(n == m) tag = 0;			/*若所有字符比较均相等则tag=0*/
	else if(n > m) tag = 1;		/*若串t只和串s的前m个字符相等则s>t*/
	else if(n < m) tag = -1;	/*若串s只和串t的前n个字符相等则s<t*/
	return tag;					
}

void main(void)
{
	DString	myString1, myString2, myString3;
	int i, max1 = 10, max2 = 20, max3 = 10;
		
	/*测试初始化函数*/
	Initiate(&myString1, max1, "Data ");
	Initiate(&myString2, max2, "Structure");
	Initiate(&myString3, max3, "");

	/*测试插入函数*/
	Insert(&myString2, 0, myString1);
	for(i = 0; i < myString2.length; i++)
		printf("%c", myString2.str[i]);
	printf("\n");

	/*测试删除函数*/
	Delete(&myString2, 0, 5);
	for(i = 0; i < myString2.length; i++)
		printf("%c", myString2.str[i]);
	printf("\n");

	/*测试取子串函数*/
	SubString(&myString2, 0, 5, &myString3);
	for(i = 0; i < myString3.length; i++)
		printf("%c", myString3.str[i]);
	printf("\n");

	/*测试撤消函数*/
	Destroy(&myString1);
	Destroy(&myString2);
}
