#include <stdio.h>
#include <malloc.h>

typedef char DataType;
#include "InThreadIterator.h"

ThreadBiNode *GetTreeNode(DataType item, ThreadBiNode *left, ThreadBiNode *right)
{
	ThreadBiNode *p;

	p = (ThreadBiNode *)malloc(sizeof(ThreadBiNode));

	p->data = item;
	p->leftChild = left;
	p->rightChild = right;

	return p;
}

void MakeCharTree(ThreadBiNode **root)
{
	ThreadBiNode *b, *c, *d, *e, *f, *g;

	g = GetTreeNode('G', NULL, NULL);
	d = GetTreeNode('D', NULL, g);
	b = GetTreeNode('B', d, NULL);
	e = GetTreeNode('E', NULL, NULL);
	f = GetTreeNode('F', NULL, NULL);
	c = GetTreeNode('C', e, f);
	*root = GetTreeNode('A', b, c);
}

void main(void)
{
	ThreadBiNode *root;
	ThreadBiTree tree;

	MakeCharTree(&root);

	CreatInThread(&root);
	
	ThreadInitiate(&tree, root);
	printf("二叉树中序正向遍历序列为：");
	for(First(&tree); !EndOfNext(&tree); Next(&tree))
		printf("%c  ", tree.current->data);
}
