#include <stdio.h>

typedef int KeyType;
typedef struct
{
	KeyType key;
} DataType;
#define MaxSize 100
#include "SeqList.h"

int OrderSeqSearch(SeqList S, DataType x)
{
	int i = 0;
	while(i < S.size && S.list[i].key < x.key) i++;

	if(S.list[i].key == x.key) return i;
	else return -1;
}

void main(void)
{
	SeqList myS = {{2, 4, 6, 8, 10, 12}, 6};
	DataType x = {7};
	int i;

	if((i = OrderSeqSearch(myS, x)) != -1 )
		printf("该数据元素位置为 %d ", i);
	else 
		printf("查找失败");
}
