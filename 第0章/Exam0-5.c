#include <stdio.h>							/*���ļ�����pringtf()�Ⱥ���*/
#define MaxSize  100						/*����MaxSizeΪ100*/
typedef int DataType;						/*����DataTypeΪint*/
#include "SeqList.h"						/*�������Ա��ļ�*/

void main(void)
{
	SeqList myList;
	int i , x, n = 10, a[10] = {1,2,3,4,5,6,7,8,9,10};

	ListInitiate(&myList);					/*��ʼ��*/
	for(i = 0; i < n; i++)
	{
		if(ListInsert(&myList, i, a[i]) == 0) 	/*����10������Ԫ��*/
		{
			printf("����! \n");
			return;
		}
	}
	
	n = ListLength(myList);
	for(i = 0; i < n; i++)
	{
		if(ListGet(myList, i, &x) == 0) 		/*ȡԪ��*/
		{
			printf("����! \n");
			return;
		}
		else printf("%d    ", x);			/*��ʾ����Ԫ��*/
	}	
}
