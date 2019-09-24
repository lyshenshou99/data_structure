#include <stdio.h>
#define MaxSize 100

typedef struct
{
	char str[MaxSize];
	int length;
} String;

//Assign(S, T)
//Length(S)
//Compare(S, T)
//Search(S, T)
//Replace(S, T, V)

int Insert(String *S, int pos, String T)
/*�ڴ�S��posλ�ò����Ӵ�T*/
{
	int i;

	if(pos < 0)
	{
		printf("����pos����");
		return 0;
	}
	else if(S->length + T.length > MaxSize)
	{
		printf("����ռ䲻���޷����룡");
		return 0;
	}
	else
	{
		for(i = S->length-1; i >= pos; i--)
			S->str[i+T.length] = S->str[i];		/*Ϊ������׼��*/

		for(i = 0; i < T.length; i++)
			S->str[pos+i] = T.str[i];				/*����*/

		S->length += T.length;						/*�����µ�Ԫ�ظ���*/
		return 1;
	}
}

int Delete(String *S, int pos, int len)
{
	int i;

	if(S->length <= 0)
	{
		printf("������δ����ַ���Ԫ�ؿ�ɾ! \n");
		return 0;
	}
	else if(pos < 0 || len < 0 || pos+len > S->length)
	{
		printf("����pos��len����");
		return 0;
	}
	else
	{
		for(i = pos+len; i <= S->length-1; i++)
			S->str[i-len] = S->str[i];				/*����ǰ��*/
		S->length -= len;						/*�����µĳ���ֵ*/
		return 1;
	}
}

int SubString(String S, int pos, int len, String *T)
{
	int i;

	if(pos < 0 || len < 0 || pos+len > S.length)
	{
		printf("����pos��len����");
		return 0;
	}
	else 
	{
		for(i = 0; i < len; i++)
			T->str[i] = S.str[pos+i];				/*���Ӵ�T��ֵ*/

		T->length = len;						/*���Ӵ�T�ĳ�����ֵ*/
		return 1;
	}
}

