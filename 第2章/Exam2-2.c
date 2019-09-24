#include <stdio.h>							
#define MaxSize  100						/*定义MaxSize为100*/
typedef struct Student
{
	long number;							/*学号数据项*/
	char name[10];							/*姓名数据项*/
	char sex[3];							/*性别数据项*/
	int  age;								/*年龄数据项*/
} StudentType;								/*结构体StudentType*/

typedef StudentType DataType;	/*定义DataType为StudentType数据类型*/
#include "SeqList.h"						/*包含顺序表文件*/

void main(void)
{
	SeqList myList;
	int i;
	StudentType  x[3] = {{2000001, "张三", "男", 20}, 
						{2000002, "李四", "男", 21},
						{2000003, "王五", "女", 22}};
	StudentType s;

	ListInitiate(&myList);					/*初始化函数调用*/
	ListInsert(&myList, 0, x[0]);				/*插入函数调用*/
	ListInsert(&myList, 1, x[1]);
	ListInsert(&myList, 2, x[2]);
	
	for(i = 0; i < ListLength(myList); i++)	/*元素个数函数调用*/
	{
		if(ListGet(myList, i, &s) == 0) 		/*取元素函数调用*/
		{
			printf("错误! \n");
			return;
		}
		else
			/*显示数据元素*/
			printf("%d   %s   %s   %d\n", s.number, s.name, s.sex, s.age);
	}	
}
