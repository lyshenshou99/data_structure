//4-13 设串采用静态数组存储结构，编写函数实现两个串的比较Compare(S, T)。要求比较结果有大于、等于和小于三种情况。
#include <stdio.h>
#define MaxSize 100

#include "SString.h"				/*包含静态数组的串操作文件*/

int Compare(String s, String t)
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
	String myString1 = {"Data ", 5}, 
		 myString2 = {"Structure", 9};
	int result;

	result = Compare(myString2, myString1);
	printf("result = %d", result);
}
