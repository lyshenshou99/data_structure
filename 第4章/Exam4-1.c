#include <string.h>
#include <stdio.h>

void ReverseName(char *name, char *newName)
{
		char *p;

		p = strchr(name, ' ');		//p指在空格' '位置

		*p = '\0';					//把空格换为'\0'，因此name的长度只包括名
			
		strcpy(newName, p+1);		//p+1是name的姓，因此newName等于name的姓
		strcat(newName, ",");		// newName等于姓加逗号
		strcat(newName, name);		// newName等于姓加逗号加名

		*p = ' ';				//恢复name为开始时的状态
}

void main(void)
{
		char name[] = "William Topp", newName[30];
	
		ReverseName(name, newName);
		printf("ReverseName: %s", newName);
}
