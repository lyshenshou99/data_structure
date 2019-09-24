typedef struct snode
{
	DataType data;
	struct snode *next;
} LSNode;

void StackInitiate(LSNode **head)
/*��ʼ����ͷ�����ʽ��ջ*/
{
	if((*head = (LSNode *)malloc(sizeof(LSNode))) == NULL) exit(1);
	(*head)->next = NULL;
}

int StackNotEmpty(LSNode *head)
 /*�ж�ջ�Ƿ�ǿգ��ǿշ���1���շ���0*/
{
	if(head->next == NULL) return 0;
	else return 1;
}

int StackPush(LSNode *head, DataType x) 
/*������Ԫ��x������ʽ��ջhead��ջ����Ϊ�µ�ջ�� */
{
	LSNode *p;

	if((p = (LSNode *)malloc(sizeof(LSNode))) == NULL)
	{
		printf("�ڴ�ռ䲻���޷�����! \n");
		return 0;
	}

	p->data = x;
	p->next = head->next;				/*�½������ջ��*/
	head->next = p; 					/*�½���Ϊ�µ�ջ��*/
	return 1;
}

int StackPop(LSNode *head, DataType *d)
/*��ջ����ջ��Ԫ���ɲ���d����*/
{
	LSNode *p = head->next;
	if(p == NULL) 
	{
		printf("��ջ�ѿճ���");
		return 0;
	}

	head->next = p->next;			/*ɾ��ԭջ�����*/
	*d = p->data; 					/*ԭջ�����Ԫ�ظ���d*/
	free(p); 						/*�ͷ�ԭջ������ڴ�ռ�*/
	return 1;
}

int StackTop(LSNode *head, DataType *d)
 /*ȡջ��Ԫ�ز���ջ��Ԫ���ɲ���d����*/
{
	LSNode *p = head->next;
	if(p == NULL) 
	{
		printf("��ջ�ѿճ���");
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