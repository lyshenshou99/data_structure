#include <stdio.h>
void Display(int n)
{
	int i;

	for(i = 1; i <= n; i++)
		printf("%d   ", n);
	printf("%\n");

	if(n > 0) Display(n - 1);			/*�ݹ�*/
	/*n<=0Ϊ�ݹ���ڣ��ݹ����Ϊ�����*/
}

void main(void)
{
	Display(4);
}
