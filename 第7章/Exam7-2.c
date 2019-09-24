#include <stdlib.h>
#include <stdio.h>

typedef char DataType;

#include "BiTree.h"
#include "BiTreeTraverse.h"

void Visit(DataType item)
{
	printf("%c ", item);
}

void PrintBiTree(BiTreeNode *bt, int n)
{
	int i;

	if(bt == NULL) return;					/*递归出口*/

	PrintBiTree(bt->rightChild, n+1);		/*遍历打印右子树*/
	
	/*访问根结点*/
	for(i = 0; i < n-1; i++) printf("   ");
	if(n > 0)
	{
		printf("---");
		printf("%c\n", bt->data);
	}

	PrintBiTree(bt->leftChild, n+1);		/*遍历打印左子树*/
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

	PrintBiTree(root, 0);

	printf("前序遍历：");
	PreOrder(root->leftChild, Visit);
	printf("\n中序遍历：");
	InOrder(root->leftChild, Visit);
	printf("\n后序遍历：");
	PostOrder(root->leftChild, Visit);

	Destroy(&root);
}
