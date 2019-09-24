#include <stdlib.h>
#include <stdio.h>

typedef char DataType;

#include "Bitree.h"

void PreOrder(BiTreeNode *t, void visit(DataType item))
/*使用visit()函数前序遍历二叉树t*/
{
	if(t != NULL)
	{
		visit(t->data);
		PreOrder(t->leftChild, visit);
		PreOrder(t->rightChild, visit);
	}
}

void visit(DataType item)
{
	printf("%c ", item);
}

void main(void)
{
	BiTreeNode *root, *p, *pp;

	Initiate(&root);
	p = InsertLeftNode(root, 'A');
	p = InsertLeftNode(p, 'B');
	p = InsertLeftNode(p, 'D');
	p = InsertRightNode(p, 'G');
	p = InsertRightNode(root->leftChild, 'C');
	pp = p;
	InsertLeftNode(p, 'E');
	InsertRightNode(pp, 'F');

	printf("前序遍历：");
	PreOrder(root->leftChild, visit);

	Destroy(&root);
}
