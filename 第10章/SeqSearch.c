#include <stdio.h>

typedef int KeyType;
typedef struct
{
	KeyType key;
} DataType;
#define MaxSize 100
#include "SeqList.h"

int SeqSearch(SeqList S, DataType x)
{
	int i = 0;
	while(i < S.size && S.list[i].key != x.key) i++;

	if(S.list[i].key == x.key) return i;
	else return -1;
}

void main(void)
{
	SeqList myS = {{710,342,45,686,6,841,429,134,68,264}, 10};
	DataType x = {687};
	int i;

	if((i = SeqSearch(myS, x)) != -1 )
		printf("该数据元素位置为 %d ", i);
	else 
		printf("查找失败");
}
