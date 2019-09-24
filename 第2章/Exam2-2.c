#include <stdio.h>							
#define MaxSize  100						/*����MaxSizeΪ100*/
typedef struct Student
{
	long number;							/*ѧ��������*/
	char name[10];							/*����������*/
	char sex[3];							/*�Ա�������*/
	int  age;								/*����������*/
} StudentType;								/*�ṹ��StudentType*/

typedef StudentType DataType;	/*����DataTypeΪStudentType��������*/
#include "SeqList.h"						/*����˳����ļ�*/

void main(void)
{
	SeqList myList;
	int i;
	StudentType  x[3] = {{2000001, "����", "��", 20}, 
						{2000002, "����", "��", 21},
						{2000003, "����", "Ů", 22}};
	StudentType s;

	ListInitiate(&myList);					/*��ʼ����������*/
	ListInsert(&myList, 0, x[0]);				/*���뺯������*/
	ListInsert(&myList, 1, x[1]);
	ListInsert(&myList, 2, x[2]);
	
	for(i = 0; i < ListLength(myList); i++)	/*Ԫ�ظ�����������*/
	{
		if(ListGet(myList, i, &s) == 0) 		/*ȡԪ�غ�������*/
		{
			printf("����! \n");
			return;
		}
		else
			/*��ʾ����Ԫ��*/
			printf("%d   %s   %s   %d\n", s.number, s.name, s.sex, s.age);
	}	
}
