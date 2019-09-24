#include <malloc.h>
#include <string.h>

void main(void)
{
	int length = 100;
	char *str, s1[] = "Data Structure";

	str = (char *)malloc(sizeof(char) * length);
	strcpy(str, s1);
	free(str);
}