/*�ļ�SCLinList.h*/
typedef struct node
{
	DataType data;
	struct node *next;
} SCLNode;									/*���ṹ�嶨��*/

void SCLLInitiate(SCLNode **head) 				/*��ʼ��*/
{
	if((*head = (SCLNode *)malloc(sizeof(SCLNode))) == NULL) exit(1);
	(*head)->next = *head;
}

int SCLLInsert(SCLNode *head, int i, DataType x)	/*����һ�����*/
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
		printf("����λ�ò�����");
		return 0;
	}

	if((q = (SCLNode *)malloc(sizeof(SCLNode))) == NULL) exit(1);
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;
}

int SCLLDelete(SCLNode *head, int i, DataType *x)	/*ɾ��һ�����*/
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
		printf("ɾ��λ�ò�����");
		return 0;
	}

	q = p->next;
	p->next = p->next->next;
	*x = q->data;
	free(q);
	return 1;
}

int SCLLGet(SCLNode *head, int i, DataType *x)	/*ȡһ���������Ԫ��ֵ*/
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
		printf("ȡԪ��λ�ò�����");
		return 0;
	}

	*x = p->data;
	return 1;
}

int SCLLNotEmpty(SCLNode *head)				/*����ǿշ�*/
{
	if(head->next == head)	return 0;
	else return 1;
}
