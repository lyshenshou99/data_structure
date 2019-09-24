#include <stdio.h>
#include <malloc.h>
#include <string.h>

void main(void)
{
	int length = 100;					/*length为动态数组的元素个数*/
	char *str, s1[] = "Data Structure";
	int i, n;

	str = (char *)malloc(sizeof(char) * length);/*动态数组申请*/
	strcpy(str, s1);							/*把串s1的值赋给str*/
	n = strlen(str);

	printf("str = ");
	for(i = 0; i < n; i++)
		printf("%c", str[i]);
	free(str);									/*动态数组释放*/
}
