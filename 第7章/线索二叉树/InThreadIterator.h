typedef struct Node
{
	DataType data;
	struct Node *leftChild;
	struct Node *rightChild;
	int leftThread;
	int rightThread;
}ThreadBiNode;

void InThread(ThreadBiNode *current, ThreadBiNode **pre)
//������������������currentΪ��ǰ���ָ�룬preΪ��ǰ��������ǰһ���ָ��
{
	if(current != NULL)
	{
		InThread(current->leftChild, pre);		//����������������������
		if(current->leftChild == NULL)			//��ǰ�����ָ��Ϊ��ָ��ʱ
		{
			current->leftThread = 1;			//�������������
			current->leftChild = *pre;			//����������ָ��
		}
		else current->leftThread = 0;

		if(current->rightChild != NULL)			//��ǰ�����ָ��Ϊ��ָ��ʱ
			current->rightThread = 0;
		else current->rightThread = 1;

		if((*pre)->rightChild == NULL)				//ǰ������ָ��Ϊ��ָ��ʱ
		{
			(*pre)->rightThread = 1;				//�������������
			(*pre)->rightChild = current;			//����������ָ��
		}
		else current->rightThread = 0;

		*pre = current;							//ǰ����ָ����ڵ�ǰ���ָ��
		InThread(current->rightChild, pre);		//����������������������
	}
}

void CreatInThread(ThreadBiNode **root)
//����������������tree
{
	ThreadBiNode *t = *root, *pre = *root;					//����ԭ�����������ָ��
	ThreadBiNode *current;				//������ʱָ��pre

	*root = (ThreadBiNode *)malloc(sizeof(ThreadBiNode));					//����ͷ���
	if(t == NULL)								//��Ϊ����ʱ
	{
		(*root)->leftThread = 0;
		(*root)->rightThread = 1;
		(*root)->leftChild = *root;
		(*root)->rightChild = *root;
	}
	else										//��Ϊ�ǿ���ʱ
	{
		current  = t;			//��һ��������ָ��
		(*root)->leftChild = t;			//��һ��������ָ��
		(*root)->leftThread = 0;					//��һ������������

		InThread(current, &pre);				//������������

		pre->rightChild = *root;					//���һ��������ָ��
		pre->rightThread = 1;					//���һ������������
		(*root)->rightChild = pre;					//��һ��������ָ��		
		(*root)->rightThread = 1;					//��һ������������
	}
}

typedef struct
{
	ThreadBiNode *root;
	ThreadBiNode *current;
	int nextComplete;				//�������β����ǣ���������ά��
}ThreadBiTree;

void ThreadInitiate(ThreadBiTree *tree, ThreadBiNode *root)
{
	tree->root = root;
	tree->current = root;
	if(root == NULL)
		tree->nextComplete = 1;
	else 
		tree->nextComplete = 0;
}

void First(ThreadBiTree *tree)
//ʹ��ǰ���ָ��currentָ���һ�����
{
	tree->current = tree->root;
	while(tree->current->leftThread == 0) tree->current = tree->current->leftChild;

	if(tree->current == tree->root) tree->nextComplete = 1;
	else tree->nextComplete = 0;
}

void Next(ThreadBiTree *tree)
//ʹ��ǰ���ָ��ָ��ǰ������һ����㡣��β��ʱ������������Ϊ1
{
	ThreadBiNode *p = tree->current->rightChild;

	if(tree->nextComplete == 1)	return;
	
	if(tree->current->rightThread == 0)
		while(p->leftThread == 0) p = p->leftChild;
	tree->current = p;

	if(tree->current == tree->root) tree->nextComplete = 1;
}

int EndOfNext(ThreadBiTree *tree)
{
	return tree->nextComplete;
}
