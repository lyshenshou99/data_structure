typedef struct snode
{
	DataType data;
	struct snode *next;
} LSNode;

void StackInitiate(LSNode **head)
/*初始化带头结点链式堆栈*/
{
	if((*head = (LSNode *)malloc(sizeof(LSNode))) == NULL) exit(1);
	(*head)->next = NULL;
}

int StackNotEmpty(LSNode *head)
 /*判堆栈是否非空，非空返回1；空返回0*/
{
	if(head->next == NULL) return 0;
	else return 1;
}

int StackPush(LSNode *head, DataType x) 
/*把数据元素x插入链式堆栈head的栈顶作为新的栈顶 */
{
	LSNode *p;

	if((p = (LSNode *)malloc(sizeof(LSNode))) == NULL)
	{
		printf("内存空间不足无法插入! \n");
		return 0;
	}

	p->data = x;
	p->next = head->next;				/*新结点链入栈顶*/
	head->next = p; 					/*新结点成为新的栈顶*/
	return 1;
}

int StackPop(LSNode *head, DataType *d)
/*出栈并把栈顶元素由参数d带回*/
{
	LSNode *p = head->next;
	if(p == NULL) 
	{
		printf("堆栈已空出错！");
		return 0;
	}

	head->next = p->next;			/*删除原栈顶结点*/
	*d = p->data; 					/*原栈顶结点元素赋予d*/
	free(p); 						/*释放原栈顶结点内存空间*/
	return 1;
}

int StackTop(LSNode *head, DataType *d)
 /*取栈顶元素并把栈顶元素由参数d带回*/
{
	LSNode *p = head->next;
	if(p == NULL) 
	{
		printf("堆栈已空出错！");
		return 0;
	}
	*d = p->data;
	return 1;
}

void Destroy(LSNode *head)
{
	LSNode *p, *p1;

	p = head;
	while(p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}