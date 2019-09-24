typedef struct Node 
{
	DataType data;								/*������*/
	struct Node *leftChild;						/*������ָ��*/
	struct Node *rightChild;					/*������ָ��*/
}BiTreeNode;									/*���Ľṹ�嶨��*/

/*��ʼ��������������ͷ���*/
void Initiate(BiTreeNode **root)
{
	*root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	(*root)->leftChild = NULL;
	(*root)->rightChild = NULL;
}

void Destroy(BiTreeNode **root)
{
	if((*root) != NULL && (*root)->leftChild != NULL)
		Destroy(&(*root)->leftChild);

	if((*root) != NULL && (*root)->rightChild != NULL)
		Destroy(&(*root)->rightChild);

	free(*root);
}

/*����ǰ���curr�ǿգ���curr������������Ԫ��ֵΪx���½��*/
/*ԭcurr��ָ������������Ϊ�²������������*/
/*������ɹ������²������ָ�룬���򷵻ؿ�ָ��*/
BiTreeNode *InsertLeftNode(BiTreeNode *curr, DataType x)
{
	BiTreeNode *s, *t;

	if(curr == NULL) return NULL;
	
	t = curr->leftChild;			/*����ԭcurr��ָ����������ָ��*/
	s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->leftChild = t;			/*�²������������Ϊԭcurr��������*/
	s->rightChild = NULL;

	curr->leftChild = s;					/*�½���Ϊcurr��������*/
	return curr->leftChild;					/*�����²������ָ��*/
}

/*����ǰ���curr�ǿգ���curr������������Ԫ��ֵΪx���½��*/
/*ԭcurr��ָ������������Ϊ�²������������*/
/*������ɹ������²������ָ�룬���򷵻ؿ�ָ��*/
BiTreeNode *InsertRightNode(BiTreeNode *curr, DataType x)
{
	BiTreeNode *s, *t;

	if(curr == NULL) return NULL;
	
	t = curr->rightChild;			/*����ԭcurr��ָ����������ָ��*/
	s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->rightChild = t;			/*�²������������Ϊԭcurr��������*/
	s->leftChild = NULL;

	curr->rightChild = s;				/*�½���Ϊcurr��������*/
	return curr->rightChild;			/*�����²������ָ��*/
}

/*��curr�ǿգ�ɾ��curr��ָ����������*/
/*��ɾ���ɹ�����ɾ������˫�׽��ָ�룬���򷵻ؿ�ָ��*/
BiTreeNode *DeleteLeftTree(BiTreeNode *curr)
{
	if(curr == NULL || curr->leftChild == NULL) return NULL;

	Destroy(&curr->leftChild);
	curr->leftChild = NULL;
	return curr;
}

/*��curr�ǿգ�ɾ��curr��ָ����������*/
/*��ɾ���ɹ�����ɾ������˫�׽��ָ�룬���򷵻ؿ�ָ��*/
BiTreeNode *DeleteRightTree(BiTreeNode *curr)
{
	if(curr == NULL || curr->rightChild == NULL) return NULL;

	Destroy(&curr->rightChild);
	curr->rightChild = NULL;
	return curr;
}

