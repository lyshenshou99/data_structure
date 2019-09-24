#include <malloc.h>
#include <string.h>

void main(void)
{
	int length = 100;					/*length为动态数组的元素个数*/
	char *str, s1[] = "Data Structure";

	str = (char *)malloc(sizeof(char) * length);	/*动态数组申请*/
	strcpy(str, s1);							/*把s1的串值赋给str*/
	free(str);								/*动态数组释放*/
}
