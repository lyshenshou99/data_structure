#include <stdio.h>

int Gcd2(int n, int m)
{
	int tn, tm, temp;
	if(n < 0 || m < 0)
	{
		printf("������");
		return -1;
	}

	
	if(m > n) 			/*��������λ��*/
	{
		tn = m;
		tm = n;
	}
	else 				/*����������λ��*/
	{
		tn = n;
		tm = m;
	}
	while(tm != 0)		/*��ѭ���ṹ����ݹ�*/
	{
		temp = tn;
		tn = tm;
		tm = temp % tm;
	}
	return tn;			/*�������Լ��*/
}

void main(void)
{
	int y;

	y = Gcd2(30, 4);
	printf("y = %d", y);
}