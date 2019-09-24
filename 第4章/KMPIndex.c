#include <stdio.h>
#define Maxlength 100
typedef struct
{
	char str[Maxlength];
	int length;
} String;

void GetNext(String T, int next[])
/*��ģʽ��t��next[j]ֵ����next[]��*/
{
	int j = 0, k = -1;

	next[0] = -1;
	while(j < T.length)
	{
		if(k == -1 || T.str[j] == T.str[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else k = next[k];
	}
}

//int KMPIndex(String S, int start, String T, int next[])
/*��������s��start��ʼ��ģʽ��t,�ҵ�����t��s�еĿ�ʼ�ַ��±�;���򷵻�-1*/
/*����next[]�д����ģʽ��t��next[j]ֵ*/
/*{
	int i = start, j = 0, v;

	while(i < S.length && j < T.length)
	{
		if(j == -1 || S.str[i] == T.str[j])
		{
			i++;
			j++;
		}
		else j = next[j];
	}

	if(j == T.length) v = i-T.length;
	else v = -1;
	return v;
}
*/

int KMPIndex(String S, int start, String T, int next[])
{
	int i = start, j = 0, v;

	while(i < S.length && j < T.length)
	{
		if(S.str[i] == T.str[j])
		{
			i++;
			j++;
		}
		else if(j == 0) i++;
		else j = next[j];
	}

	if(j == T.length) v = i-T.length;
	else v = -1;
	return v;
}

void main(void)
{
//	String S = {{"aaaaaaaa"}, 8}, T = {{"aab"}, 3};
//	int next[8], pos;
	String S = {{"cddcdc"}, 6}, T = {{"cdc"}, 3};
	int next[8], pos;
	
	GetNext(T, next);
	pos = KMPIndex(S, 0, T, next);
	printf("pos = %d\n", pos);
}