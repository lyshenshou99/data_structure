typedef struct Node
{
	DataType data;
	struct Node *leftChild;
	struct Node *rightChild;
	int leftThread;
	int rightThread;
}ThreadBiNode;

void InThread(ThreadBiNode *current, ThreadBiNode **pre)
//中序线索化二叉树。current为当前结点指针，pre为当前结点的中序前一结点指针
{
	if(current != NULL)
	{
		InThread(current->leftChild, pre);		//中序线索化左子树二叉树
		if(current->leftChild == NULL)			//当前结点左指针为空指针时
		{
			current->leftThread = 1;			//建立左线索标记
			current->leftChild = *pre;			//建立左线索指针
		}
		else current->leftThread = 0;

		if(current->rightChild != NULL)			//当前结点左指针为空指针时
			current->rightThread = 0;
		else current->rightThread = 1;

		if((*pre)->rightChild == NULL)				//前序结点右指针为空指针时
		{
			(*pre)->rightThread = 1;				//建立右线索标记
			(*pre)->rightChild = current;			//建立右线索指针
		}
		else current->rightThread = 0;

		*pre = current;							//前序结点指针等于当前结点指针
		InThread(current->rightChild, pre);		//中序线索化右子树二叉树
	}
}

void CreatInThread(ThreadBiNode **root)
//中序线索化二叉树tree
{
	ThreadBiNode *t = *root, *pre = *root;					//保存原二叉树根结点指针
	ThreadBiNode *current;				//定义临时指针pre

	*root = (ThreadBiNode *)malloc(sizeof(ThreadBiNode));					//建立头结点
	if(t == NULL)								//当为空树时
	{
		(*root)->leftThread = 0;
		(*root)->rightThread = 1;
		(*root)->leftChild = *root;
		(*root)->rightChild = *root;
	}
	else										//当为非空树时
	{
		current  = t;			//第一个结点的左指针
		(*root)->leftChild = t;			//第一个结点的左指针
		(*root)->leftThread = 0;					//第一个结点的左线索

		InThread(current, &pre);				//线索化二叉树

		pre->rightChild = *root;					//最后一个结点的右指针
		pre->rightThread = 1;					//最后一个结点的右线索
		(*root)->rightChild = pre;					//第一个结点的右指针		
		(*root)->rightThread = 1;					//第一个结点的右线索
	}
}

typedef struct
{
	ThreadBiNode *root;
	ThreadBiNode *current;
	int nextComplete;				//正序遍历尾部标记，由派生类维护
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
//使当前结点指针current指向第一个结点
{
	tree->current = tree->root;
	while(tree->current->leftThread == 0) tree->current = tree->current->leftChild;

	if(tree->current == tree->root) tree->nextComplete = 1;
	else tree->nextComplete = 0;
}

void Next(ThreadBiTree *tree)
//使当前结点指针指向当前结点的下一个结点。到尾部时正序结束标记置为1
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
