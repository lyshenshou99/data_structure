#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include"DString.h"					/*包含动态数组的串操作文件*/

void main(void)
{
	DString	myString1, myString2, myString3;
	int i, max1 = 1, max2 = 1, max3 = 0;
		
	/*测试初始化函数*/
	Initiate(&myString1, max1, "Data-");
	Initiate(&myString2, max2, "Structure");
	Initiate(&myString3, max3, "--");
	for(i = 0; i < myString1.length; i++)
		printf("%c", myString1.str[i]);
	printf("\n");
	for(i = 0; i < myString2.length; i++)
		printf("%c", myString2.str[i]);
	printf("\n");
print(myString3);

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
	SubString(&myString1, 0, 5, &myString3);
	for(i = 0; i < myString3.length; i++)
		printf("%c", myString3.str[i]);
	printf("\n");

	/*测试撤消函数*/
	Destroy(&myString1);
	Destroy(&myString2);
	Destroy(&myString3);
}
