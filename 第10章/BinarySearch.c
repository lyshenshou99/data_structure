#include <stdio.h>

typedef int KeyType;
typedef struct
{
	KeyType key;
} DataType;
#define MaxSize 100
#include "SeqList.h"

int BinarySearch(SeqList S, DataType x)
{
	int low = 0, high = S.size-1;			//确定初始查找区间上下界
	int mid;

	while(low <= high)					
	{
		mid = (low + high) / 2;				//确定初始查找区间中心位置
		if(S.list[mid].key == x.key) return mid;		//查找成功
		else if(S.list[mid].key < x.key) low = mid + 1;		
		else if(S.list[mid].key > x.key) high = mid - 1;
	}

	return -1;											//查找失败
}

void main(void)
{
	SeqList myS = {{2, 4, 6, 8, 10, 12}, 6};
	DataType x = {6};
	int i;

	if((i = BinarySearch(myS, x)) != -1 )
		printf("该数据元素位置为 %d ", i);
	else 
		printf("查找失败");
}
