#include <string.h>
#include <stdio.h>

void ReverseName(char *name, char *newName)
{
		char *p;

		p = strchr(name, ' ');		//pָ�ڿո�' 'λ��

		*p = '\0';					//�ѿո�Ϊ'\0'�����name�ĳ���ֻ������
			
		strcpy(newName, p+1);		//p+1��name���գ����newName����name����
		strcat(newName, ",");		// newName�����ռӶ���
		strcat(newName, name);		// newName�����ռӶ��ż���

		*p = ' ';				//�ָ�nameΪ��ʼʱ��״̬
}

void main(void)
{
		char name[] = "William Topp", newName[30];
	
		ReverseName(name, newName);
		printf("ReverseName: %s", newName);
}
