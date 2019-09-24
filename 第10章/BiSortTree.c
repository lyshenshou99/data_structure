#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int KeyType;
typedef struct
{
	KeyType key;
}DataType;

typedef struct node
{
	DataType data;
	struct node *leftChild;
	struct node *rightChild;
} BiTreeNode;

int Search(BiTreeNode *root, DataType item)
{
	BiTreeNode *p;

	if(root != NULL)
	{
		p = root;
		while(p != NULL)
		{
			if(p->data.key == item.key) return 1;
			if(item.key > p->data.key) p = p->rightChild;
			else p = p->leftChild;
		}
	}
	return 0;
}

int Insert(BiTreeNode **root, DataType item)
{
	BiTreeNode *current, *parent = NULL, *p;

	current = *root;
	while(current != NULL)
	{
		if(current->data.key == item.key) return 0;
		parent = current;
		if(current->data.key < item.key) current = current->rightChild;
		else current = current->leftChild;
	}
		
	p = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	if(p == NULL)
	{
		printf("�ռ䲻��!");
		exit(1);
	}

	p->data = item;					
	p->leftChild = NULL;					
	p->rightChild = NULL;

	if(parent == NULL) *root = p;
	else if(item.key < parent->data.key)
		parent->leftChild = p;
	else 
		parent->rightChild = p;
	return 1;
}

/*
int Delete(BiTreeNode *root, DataType item)
{
	BiTreeNode *p, *parent, *min, *q;
	int tag = 0;

	p = root;
	while(p != NULL)
	{
		if(p->data.key == item.key)	break;

		if(p->data.key < item.key)
		{
			tag = 1;
			parent = p;
			p = p->rightChild;
		}
		else
		{
			parent = p;
			p = p->leftChild;
		}
	}

	if(p == NULL) return 0;
	else
	{
		//��������
		if(p->rightChild == NULL)
		{
			printf("tag = %d\n", tag);
			if(tag == 1)
				parent->rightChild = p->leftChild;
			else
				parent->leftChild = p->leftChild;
			free(p);
		}
		//��������
		else if(p->leftChild == NULL)
		{
			printf("tag = %d\n", tag);
			if(tag == 0)
				parent->leftChild = p->rightChild;
			else
				parent->rightChild = p->rightChild;
			free(p);
		}
		else
		{
			//Ѱ��ֵ���ڵ�ǰ������Сֵ����Ѱ����������������
			min = p->rightChild;
			while(min->leftChild != NULL)
			{
				parent = min;
				min = min->leftChild;
			}
			//�����������������ֵ��������ǰ�����
			p->data = min->data;
				//ɾ����������������
			Delete(p->rightChild, min->data);
		}
		return 1;
	}
}
*/

void InTraverse(BiTreeNode *root)
{
	if(root == NULL) return;
	
	if(root->leftChild != NULL)
		InTraverse(root->leftChild);

	printf("%d   ", root->data.key);

	if(root->rightChild != NULL)
		InTraverse(root->rightChild);
}

void main(void)
{
	DataType test[] = {4,5,7,2,1,9,8,11,3}, x = {9};
	int n = 9, i, s;
	BiTreeNode *root = NULL;

	for(i = 0; i < n; i++)
	{
		Insert(&root, test[i]);
	}
	PreTraverse(root);
	InTraverse(root);
	s = Search(root, x);
	if(s == 1)
		printf("\n����Ԫ��%d���ڣ�", x.key);
	else
		printf("\n����Ԫ�ز����ڣ�");

}
