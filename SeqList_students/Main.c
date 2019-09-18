#include "SeqList.h"

int main(void)
{
	SeqList myList;
	int i = 0, j = 0;
	
	StudentType x[3] = {{2001, "张三", "男", 20, 60},
						{2002, "李四", "男", 21, 75},
						{2003, "王五", "女", 22, 90}};
						
	StudentType temp, temp1;
	
	ListInitiate(&myList);
	
	ListInsert(&myList, 0, x[0]);
	ListInsert(&myList, 1, x[1]);
	ListInsert(&myList, 2, x[2]);
	
	for(i = 0; i < ListLength(myList); i++)
	{
		if(ListGet(myList, i, &temp) == 0)
		{
			printf("错误！\n");
			
			return 0;
		}
		else
		{
			printf("%d	%s	%s	%d	%.1f\n", temp.number, temp.name, temp.sex, temp.age, temp.grade);
		}
	}
	
	printf("After sorting by grade.\n");
	
	ListExchangeAsGrade(&myList);
	
	for(i = 0; i < ListLength(myList); i++)
	{
		if(ListGet(myList, i, &temp) == 0)
		{
			printf("错误！\n");
			
			return 0;
		}
		else
		{
			printf("%d	%s	%s	%d	%.1f\n", temp.number, temp.name, temp.sex, temp.age, temp.grade);
		}
	}
	
	return 0;
}
