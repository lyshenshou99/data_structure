#include <stdio.h>
#include <malloc.h>
#include <string.h>

void main(void)
{
	int length = 100;					/*lengthΪ��̬�����Ԫ�ظ���*/
	char *str, s1[] = "Data Structure";
	int i, n;

	str = (char *)malloc(sizeof(char) * length);/*��̬��������*/
	strcpy(str, s1);							/*�Ѵ�s1��ֵ����str*/
	n = strlen(str);

	printf("str = ");
	for(i = 0; i < n; i++)
		printf("%c", str[i]);
	free(str);									/*��̬�����ͷ�*/
}
