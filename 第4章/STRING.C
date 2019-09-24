#include <string.h>
#include <stdio.h>

void main(void)
{
	char s1[] ="I am a student";
	char s2[30] ="teacher";
	char s3[] ="student";
	int result;
	char s4[20], *p;

	printf("%d\n", strlen(s1));					//输出14
	printf("%d\n", strlen(s2));					//输出7
//（2）拷贝		char *strcpy(char *str1, char *str2):
		strcpy(s4, s2);								
		printf("%s\n", s4);					//输出teacher
//（3）比较		int strcmp(char *str1, char *str2):
		result = strcmp(s2, s3);				// s2 > s3
		printf("%d\n", result);					//输出1
		result = strcmp(s2, s2);				// s2 == s3
		printf("%d\n", result);					//输出0
		result = strcmp(s3, s2);				// s3 > s2
		printf("%d\n", result);					//输出-1
//（4）字符定位		char *strchr(char *str, char ch);
		p = strchr(s1, 's');						//p指在s1中字符's'的位置
		printf("%s\n", p);					//输出7
//（5）子串查找       char *strstr(char *s1, char *s2)
		p = strstr(s1, s3);
		printf("%s\n", p);					//输出7
//（6）连接		char * strcat(char *str1, char *str2):
		strcat(s2, s3);								
		printf("%s\n", s2);					//输出teacherstudent
}