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

	if(bt == NULL) return;					/*�ݹ����*/

	PrintBiTree(bt->rightChild, n+1);		/*������ӡ������*/
	
	/*���ʸ����*/
	for(i = 0; i < n-1; i++) printf("   ");
	if(n > 0)
	{
		printf("---");
		printf("%c\n", bt->data);
	}

	PrintBiTree(bt->leftChild, n+1);		/*������ӡ������*/
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

	printf("ǰ�������");
	PreOrder(root->leftChild, Visit);
	printf("\n���������");
	InOrder(root->leftChild, Visit);
	printf("\n���������");
	PostOrder(root->leftChild, Visit);

	Destroy(&root);
}
