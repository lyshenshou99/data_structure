//4-13 设串采用静态数组存储结构，编写函数实现两个串的比较Compare(S, T)。要求比较结果有大于、等于和小于三种情况。
#include <stdio.h>
#define MaxSize 100

#include "SString.h"				/*包含静态数组的串操作文件*/

void main(void)
{
	String myString1 = {"Data ", 5}, 
		 myString2 = {"Structure", 9};
	int i;

	Insert(&myString2, 0, myString1);					

	for(i = 0; i < myString2.length; i++)
		printf("%c", myString2.str[i]);
}
