#include <stdio.h>
#define Maxlength 100
#include "BFandKMP.h"

void main(void)
{
//	String S = {{"cddcdc"}, 6}, T = {{"abcde"}, 5};	/*测试例子1*/
	String S = {{"aaaaaaaa"}, 8}, T = {{"aaaab"}, 5};	/*测试例子2*/
	int next[10], count, i;
	
	count = BFIndex(S, 0, T);
	printf("Brute-Force算法比较次数: %d\n", count);

	GetNext(T, next);
	for(i = 0; i < T.length; i ++)
		printf("%d   ", next[i]);
	printf("\n");

	count = KMPIndex(S, 0, T, next);
	printf("KMP算法比较次数: %d\n", count);
}