#include <stdio.h>							/*该文件包含pringtf()等函数*/
#include <stdlib.h>							/*该文件包含exit()等函数*/
#include <malloc.h>							/*该文件包含malloc()等函数*/

typedef int DataType;						/*定义DataType为int*/
#include "LinList.h"						/*包含线性表文件*/

int ListDeleteMore(SLNode *L, DataType x)
{
	SLNode *pre, *curr, *q;
	int tag = 0;						/*初始置为删除失败标记*/

	pre = L;
	curr = L->next;
	while(curr != NULL)
	{
		if(curr->data == x)				/*找到要删除的元素x*/
		{
			q = curr;
			curr = curr->next;
			pre->next = curr;
			free(q);
			tag = 1;
		}
		else							/*继续向后查找*/
		{
			pre = curr;
			curr = curr->next;
		}
	}
	return tag;							/*返回删除成功或失败标记*/
}

void main(void)
{
	SLNode *head;
	int i , x = 89, tag;

	ListInitiate(&head);					/*初始化*/
	for(i = 0; i < 10; i++)
	{
		if(ListInsert(head, i, i+1) == 0) 	/*插入10个数据元素*/
		{
			printf("错误! \n");
			return;
		}
	}
	
	if(ListInsert(head, 5, 8) == 0) 	/*删除数据元素5*/
	{
		printf("错误! \n");
		return;
	}
	
	tag = ListDeleteMore(head, x);
	printf("tag = %d\n",tag);

	for(i = 0; i < ListLength(head); i++)
	{
		ListGet(head, i, &x); 		/*取元素*/
		printf("%d    ", x);			/*显示数据元素*/
	}
	
	Destroy(&head);
}
