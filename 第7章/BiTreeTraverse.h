void PreOrder(BiTreeNode *t, void visit(DataType item))
//ʹ��visit(item)����ǰ�����������t
{
	if(t != NULL)
	{
		visit(t->data);
		PreOrder(t->leftChild, visit);
		PreOrder(t->rightChild, visit);
	}
}

void InOrder(BiTreeNode *t, void visit(DataType item))
//ʹ��visit(item)�����������������t
{
	if(t != NULL)
	{
		InOrder(t->leftChild, visit);
		visit(t->data);
		InOrder(t->rightChild, visit);
	}
}

void PostOrder(BiTreeNode *t, void visit(DataType item))
//ʹ��visit(item)�����������������t
{
	if(t != NULL)
	{
		PostOrder(t->leftChild, visit);
		PostOrder(t->rightChild, visit);
		visit(t->data);
	}
}


