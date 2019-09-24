#include <stdio.h>
#define Maxlength 100
typedef struct
{
	char str[Maxlength];
	int length;
} String;

int BFIndex(String S, int start, String T)
{
	int i = start, j = 0, v;

	while(i < S.length && j < T.length)
	{
		if(S.str[i] == T.str[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i-j+1;
			j = 0;
		}
	}

	if(j == T.length) v = i-T.length;
	else v = -1;
	return v;
}

void main(void)
{
	String S = {{"cddcdc"}, 6}, T = {{"cdc"}, 3};
	int pos;
	
	pos = BFIndex(S, 0, T);
	printf("pos = %d\n", pos);
}