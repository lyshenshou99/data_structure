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
	int low = 0, high = S.size-1;			//ȷ����ʼ�����������½�
	int mid;

	while(low <= high)					
	{
		mid = (low + high) / 2;				//ȷ����ʼ������������λ��
		if(S.list[mid].key == x.key) return mid;		//���ҳɹ�
		else if(S.list[mid].key < x.key) low = mid + 1;		
		else if(S.list[mid].key > x.key) high = mid - 1;
	}

	return -1;											//����ʧ��
}

void main(void)
{
	SeqList myS = {{2, 4, 6, 8, 10, 12}, 6};
	DataType x = {6};
	int i;

	if((i = BinarySearch(myS, x)) != -1 )
		printf("������Ԫ��λ��Ϊ %d ", i);
	else 
		printf("����ʧ��");
}
