#include <stdio.h>
#include <malloc.h>

typedef int KeyType;
#include "HashList.h"

void main(void)
{
	HashTable myHashTable;
	DataType a[] = {180,750,600,430,541,900,460}, item = {430}; 
	int i, j, k, n = 7, m =13;

	Initiate(&myHashTable, m);
	for(i = 0; i < n; i++)
		Insert(&myHashTable, a[i]);

	for(i = 0; i < n; i++)
	{
		j = Find(&myHashTable, a[i]);
		printf("j = %d   ht[] = %d\n", j, myHashTable.ht[j].data.key);
	}
	k = Find(&myHashTable, item);
	if(k >= 0) printf("���ҳɹ�������Ԫ��%d�Ĺ�ϣ��ַΪ%d\n", item.key, k);
	else printf("����ʧ��\n");

	Delete(&myHashTable, item);
	k = Find(&myHashTable, item);
	if(k >= 0) printf("���ҳɹ�������Ԫ��%d�Ĺ�ϣ��ַΪ%d\n", item.key, k);
	else printf("����ʧ��\n");

	Destroy(&myHashTable);
}