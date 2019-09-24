typedef struct
{
	char *str;
	int maxLength;			
	int length;
} DString;

void Initiate(DString *S, int max, char *string)
{
	int i, m;
	
	S->length = strlen(string);
	if(S->length > max) m = S->length;
	else m = max;
	S->maxLength = m;						/*�ö�̬����Ԫ��������*/
	S->str = (char *)malloc(sizeof(char)*m);	/*���붯̬����ռ�*/					/*�ô��ĵ�ǰ����ֵ*/
	for(i = 0; i < S->length; i++)
		S->str[i] = string[i];					/*��ֵ��ֵ*/
}


int Insert(DString *S, int pos, DString T)
/*�ڴ�S��posλ�ò����Ӵ�T*/
{
	int i;
	char *p;

	if(pos < 0)
	{
		printf("����pos����");
		return 0;
	}
	else
	{
		if(S->length + T.length > S->maxLength)
		{
			/*������������ռ䣬ԭ����Ԫ�ش�����������ǰ��*/
			p = (char *)realloc
			(S->str, (S->length+T.length)*sizeof(char));
			if(p == NULL)
			{
				printf("�ڴ�ռ䲻�㣡");
				return 0;
			}
			S->maxLength = S->length+T.length;
		}

		for(i = S->length-1; i >= pos; i--)
			S->str[i+T.length] = S->str[i];		/*���κ�������Ԫ��*/

		for(i = 0; i < T.length; i++)
			S->str[pos+i] = T.str[i];			/*����*/

		S->length = S->length + T.length;		/*�����µĴ�����ֵ*/
		return 1;
	}
}

int Delete(DString *S, int pos, int len)
{
	int i;

	if(S->length <= 0)
	{
		printf("������δ����ַ���Ԫ�ؿ�ɾ! \n");
		return 0;
	}
	else if(pos < 0 || len < 0 || pos+len > S->length)
	{
		printf("����pos��len���Ϸ�");
		return 0;
	}
	else
	{
		for(i = pos+len; i < S->length; i++)
			S->str[i-len] = S->str[i];			/*����ǰ������Ԫ��*/

		S->length = S->length - len;			/*�����µĴ�����ֵ*/
		return 1;
	}
}

int SubString(DString *S, int pos, int len, DString *T)
{
	int i;
	char *p;

	if(pos < 0 || len < 0 || pos+len > S->length)
	{
		printf("����pos��len����");
		return 0;
	}

	if(T->maxLength < len)
	{
		p = (char *)realloc(T->str, len*sizeof(char));
		if(p == NULL)
		{
			printf("�ڴ�ռ䲻�㣡");
			return 0;
		}
		T->maxLength = len;
	}
	
	for(i = 0; i < len; i++)
		T->str[i] = S->str[pos+i];	

	T->length = len;						
	return 1;
}

void Destroy(DString *S)
{
	free(S->str);
	S->maxLength = 0;
	S->length = 0;
}
void print(DString S)
{
	int i;
	for(i = 0; i < S.length; i++)
		printf("%c", S.str[i]);
	printf("\n");
}

