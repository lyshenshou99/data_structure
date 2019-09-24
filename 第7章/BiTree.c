#include <stdlib.h>
#include <stdio.h>

typedef char DataType;
typedef struct Node 
{
	DataType data;							/*������*/
	struct Node *leftChild;						/*������ָ��*/
	struct Node *rightChild;						/*������ָ��*/
}BiTreeNode;									/*���Ľṹ�嶨��*/

/*��ʼ�������������ĸ����*/
void Initiate(BiTreeNode **root)
{
	*root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	(*root)->leftChild = NULL;
	(*root)->rightChild = NULL;
}

/*����ǰ���curr�ǿգ���curr������������Ԫ��ֵΪx���½��*/
/*ԭcurr��ָ������������Ϊ�²������������*/
/*������ɹ������²������ָ�룬���򷵻ؿ�ָ��*/
BiTreeNode *InsertLeftNode(BiTreeNode *curr, DataType x)
{
	BiTreeNode *s, *t;

	if(curr == NULL) return NULL;
	
	t = curr->leftChild;					/*����ԭcurr��ָ����������ָ��*/
	s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->leftChild = t;				/*�²������������Ϊԭcurr��������*/
	s->rightChild = NULL;

	curr->leftChild = s;					/*�½���Ϊcurr��������*/
	return curr->leftChild;				/*�����²������ָ��*/
}

/*����ǰ���curr�ǿգ���curr������������Ԫ��ֵΪx���½��*/
/*ԭcurr��ָ������������Ϊ�²������������*/
/*������ɹ������²������ָ�룬���򷵻ؿ�ָ��*/
BiTreeNode *InsertRightNode(BiTreeNode *curr, DataType x)
{
	BiTreeNode *s, *t;

	if(curr == NULL) return NULL;
	
	t = curr->rightChild;				/*����ԭcurr��ָ����������ָ��*/
	s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->rightChild = t;				/*�²������������Ϊԭcurr��������*/
	s->leftChild = NULL;

	curr->rightChild = s;				/*�½���Ϊcurr��������*/
	return curr->rightChild;				/*�����²������ָ��*/
}

/*��curr�ǿգ�ɾ��curr��ָ����������*/
/*��ɾ���ɹ�����ɾ������˫�׽��ָ�룬���򷵻ؿ�ָ��*/
BiTreeNode *DeleteLeftTree(BiTreeNode *curr)
{
	if(curr == NULL || curr->leftChild == NULL) return NULL;

	free(curr->leftChild);
	curr->leftChild = NULL;
	return curr;
}

/*��curr�ǿգ�ɾ��curr��ָ����������*/
/*��ɾ���ɹ�����ɾ������˫�׽��ָ�룬���򷵻ؿ�ָ��*/
BiTreeNode *DeleteRightTreeree(BiTreeNode *curr)
{
	if(curr == NULL || curr->rightChild == NULL) return NULL;

	free(curr->rightChild);
	curr->rightChild = NULL;
	return curr;
}

void PreOrder(BiTreeNode *t, void visit(DataType item))
/*ʹ��visit()����ǰ�����������t*/
{
	if(t != NULL)
	{
		visit(t->data);
		PreOrder(t->leftChild, visit);
		PreOrder(t->rightChild, visit);
	}
}

void InOrder(BiTreeNode *t, void visit(DataType item))
/*ʹ��visit()�����������������t*/
{
	if(t != NULL)
	{
		InOrder(t->leftChild, visit);
		visit(t->data);
		InOrder(t->rightChild, visit);
	}
}

void PostOrder(BiTreeNode *t, void visit(DataType item))
/*ʹ��visit()�����������������t*/
{
	if(t != NULL)
	{
		PostOrder(t->leftChild, visit);
		PostOrder(t->rightChild, visit);
		visit(t->data);
	}
}

void Destroy(BiTreeNode **root)
{
	if((*root) != NULL && (*root)->leftChild != NULL)
		Destroy(&(*root)->leftChild);

	if((*root) != NULL && (*root)->rightChild != NULL)
		Destroy(&(*root)->rightChild);

	free(*root);
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

	printf("ǰ�������");
	PreOrder(root->leftChild, visit);
	printf("\n���������");
	InOrder(root->leftChild, visit);
	printf("\n���������");
	PostOrder(root->leftChild, visit);

	Destroy(&root);
}
