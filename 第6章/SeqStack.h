typedef struct
{
	DataType stack[MaxStackSize];			
	int top;
} SeqStack;

void StackInitiate(SeqStack *S)				/*��ʼ��˳���ջS*/
{
	S->top = 0;							/*�����ʼջ���±�ֵ*/	
}

int StackNotEmpty(SeqStack S)
/*��˳���ջS�ǿշ񣬷ǿ��򷵻�1�����򷵻�0*/
{
	if(S.top <= 0)	return 0;
	else return 1;
}

int StackPush(SeqStack *S, DataType x)
/*������Ԫ��ֵxѹ��˳���ջS����ջ�ɹ��򷵻�1�����򷵻�0 */
{
	if(S->top >= MaxStackSize)
	{
		printf("��ջ�����޷�����! \n");
		return 0;
	}
	else
	{
		S->stack[S->top] = x;
		S->top ++;
		return 1;
	}
}

int StackPop(SeqStack *S, DataType *d)
/*����˳���ջS��ջ������Ԫ��ֵ������d ����ջ�ɹ��򷵻�1�����򷵻�0*/
{
	if(S->top <= 0)
	{
		printf("��ջ�ѿ�������Ԫ�س�ջ! \n");
		return 0;
	}
	else
	{
		S->top --;
		*d = S->stack[S->top];
		return 1;
	}
}

int StackTop(SeqStack S, DataType *d)
/*ȡ˳���ջS�ĵ�ǰջ������Ԫ��ֵ������d ���ɹ��򷵻�1�����򷵻�0*/
{
if(S.top <= 0)
	{
		printf("��ջ�ѿ�! \n");
		return 0;
	}
	else
	{
		*d = S.stack[S.top - 1];
		return 1;
	}
}
