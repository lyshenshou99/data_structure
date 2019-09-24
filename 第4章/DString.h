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
	S->maxLength = m;						/*置动态数组元素最大个数*/
	S->str = (char *)malloc(sizeof(char)*m);	/*申请动态数组空间*/					/*置串的当前长度值*/
	for(i = 0; i < S->length; i++)
		S->str[i] = string[i];					/*赋值串值*/
}


int Insert(DString *S, int pos, DString T)
/*在串S的pos位置插入子串T*/
{
	int i;
	char *p;

	if(pos < 0)
	{
		printf("参数pos出错！");
		return 0;
	}
	else
	{
		if(S->length + T.length > S->maxLength)
		{
			/*重新申请数组空间，原数组元素存放在新数组的前面*/
			p = (char *)realloc
			(S->str, (S->length+T.length)*sizeof(char));
			if(p == NULL)
			{
				printf("内存空间不足！");
				return 0;
			}
			S->maxLength = S->length+T.length;
		}

		for(i = S->length-1; i >= pos; i--)
			S->str[i+T.length] = S->str[i];		/*依次后移数据元素*/

		for(i = 0; i < T.length; i++)
			S->str[pos+i] = T.str[i];			/*插入*/

		S->length = S->length + T.length;		/*产生新的串长度值*/
		return 1;
	}
}

int Delete(DString *S, int pos, int len)
{
	int i;

	if(S->length <= 0)
	{
		printf("数组中未存放字符无元素可删! \n");
		return 0;
	}
	else if(pos < 0 || len < 0 || pos+len > S->length)
	{
		printf("参数pos和len不合法");
		return 0;
	}
	else
	{
		for(i = pos+len; i < S->length; i++)
			S->str[i-len] = S->str[i];			/*依次前移数据元素*/

		S->length = S->length - len;			/*产生新的串长度值*/
		return 1;
	}
}

int SubString(DString *S, int pos, int len, DString *T)
{
	int i;
	char *p;

	if(pos < 0 || len < 0 || pos+len > S->length)
	{
		printf("参数pos和len出错！");
		return 0;
	}

	if(T->maxLength < len)
	{
		p = (char *)realloc(T->str, len*sizeof(char));
		if(p == NULL)
		{
			printf("内存空间不足！");
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

