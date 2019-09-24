#include <stdio.h>
#define Maxlength 100
typedef struct
{
	char str[Maxlength];
	int length;
} String;

void GetNext(String T, int next[])
/*求模式串t的next[j]值存于next[]中*/
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
/*查找主串s从start开始的模式串t,找到返回t在s中的开始字符下标;否则返回-1*/
/*数组next[]中存放有模式串t的next[j]值*/
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