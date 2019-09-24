/*文件SCLinList.h*/
typedef struct node
{
	DataType data;
	struct node *next;
} SCLNode;									/*结点结构体定义*/

void SCLLInitiate(SCLNode **head) 				/*初始化*/
{
	if((*head = (SCLNode *)malloc(sizeof(SCLNode))) == NULL) exit(1);
	(*head)->next = *head;
}

int SCLLInsert(SCLNode *head, int i, DataType x)	/*插入一个结点*/
{
	SCLNode *p, *q;
	int j;

	p = head->next;	j = 1;
	while(p != head && j < i - 1)
	{
		p = p->next;	j++;
	}

	if(j != i - 1 && i != 1)
	{
		printf("插入位置参数错！");
		return 0;
	}

	if((q = (SCLNode *)malloc(sizeof(SCLNode))) == NULL) exit(1);
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;
}

int SCLLDelete(SCLNode *head, int i, DataType *x)	/*删除一个结点*/
{
	SCLNode *p, *q;
	int j;

	p = head;	j = 0;
	while(p->next != head && j < i - 1)
	{
		p = p->next;	j++;
	}

	if(j != i - 1)
	{
		printf("删除位置参数错！");
		return 0;
	}

	q = p->next;
	p->next = p->next->next;
	*x = q->data;
	free(q);
	return 1;
}

int SCLLGet(SCLNode *head, int i, DataType *x)	/*取一个结点数据元素值*/
{
	SCLNode *p;
	int j;

	p = head;	j = 0;
	while(p->next != head && j < i)
	{
		p = p->next;	j++;
	}

	if(j != i)
	{
		printf("取元素位置参数错！");
		return 0;
	}

	*x = p->data;
	return 1;
}

int SCLLNotEmpty(SCLNode *head)				/*链表非空否*/
{
	if(head->next == head)	return 0;
	else return 1;
}
