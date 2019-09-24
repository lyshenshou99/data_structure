typedef struct
{
	DataType stack[MaxStackSize];			
	int top;
} SeqStack;

void StackInitiate(SeqStack *S)				/*初始化顺序堆栈S*/
{
	S->top = 0;							/*定义初始栈顶下标值*/	
}

int StackNotEmpty(SeqStack S)
/*判顺序堆栈S非空否，非空则返回1，否则返回0*/
{
	if(S.top <= 0)	return 0;
	else return 1;
}

int StackPush(SeqStack *S, DataType x)
/*把数据元素值x压入顺序堆栈S，入栈成功则返回1，否则返回0 */
{
	if(S->top >= MaxStackSize)
	{
		printf("堆栈已满无法插入! \n");
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
/*弹出顺序堆栈S的栈顶数据元素值到参数d ，出栈成功则返回1，否则返回0*/
{
	if(S->top <= 0)
	{
		printf("堆栈已空无数据元素出栈! \n");
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
/*取顺序堆栈S的当前栈顶数据元素值到参数d ，成功则返回1，否则返回0*/
{
if(S.top <= 0)
	{
		printf("堆栈已空! \n");
		return 0;
	}
	else
	{
		*d = S.stack[S.top - 1];
		return 1;
	}
}
