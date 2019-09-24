#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int DataType;
typedef struct node
{
	DataType data;
	struct node *leftChild;
	struct node *rightChild;
} BiTreeNode;

BiTreeNode *Search(BiTreeNode *root, DataType item)
{
	BiTreeNode *p;

	if(root != NULL)
	{
		p = root;
		while(p != NULL)
		{
//printf("data = %d", p->data);
			if(p->data == item) return p;
			if(item > p->data) p = p->rightChild;
			else p = p->leftChild;
		}
	}
	return NULL;
}

BiTreeNode *Insert(BiTreeNode *root, DataType item)
{
	BiTreeNode *current, *parent = NULL, *p;

	if(root != NULL)
	{
		current = root;
		while(current != NULL)
		{
			if(current->data == item) return current;
			parent = current;
			if(current->data < item) current = current->rightChild;
			else current = current->leftChild;
		}
	}
		
	p = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	if(p == NULL)
	{
		printf("空间不够!");
		exit(1);
	}

	p->data = item;					
	p->leftChild = NULL;					
	p->rightChild = NULL;

	if(parent == NULL) return p;

	if(item < parent->data)
		parent->leftChild = p;
	else 
		parent->rightChild = p;
	return p;
}

int Search2(BiTreeNode *t, BiTreeNode *c, keytype key, BiTreeNode **p, BiTreeNode **f)
{
	if(c == NULL) 
	{
		(*p) = t;
		(*f) = NULL;
		return 0;
	}
	if(c->key == key) 
	{
		(*p) = c;
		(*f) = t;
		return 1;
	}
	if(c->key > key) return Search2(c, c->LChild, key, p, f);
	else return Search2(c, c->RChild, key, p, f);
}

BiTreeNode *Delete(BiTreeNode *t, BiTreeNode *c, keytype key)
{
	BiTreeNode *q, *s, *ss, *p, *f;
	int tag;
	tag = Search2(t, c, key, &p, &f);
	if(tag == 1)
	{
		if(p->LChild == NULL && p->RChild == NULL)
		{
			if(f == p) f = NULL;
			else
			{
				if(f->key > p->key) f->LChild = NULL;
				else f->RChild = NULL;
			}
			free(p);
			return f;
		}
		if(p->LChild == NULL)
		{
			if(f == p) f = p->RChild;
			else
			{
				if(f->key > p->key) f->LChild = p->RChild;
				else f->RChild = p->RChild;
			}
			free(p);
			return f;
		}
		if(p->RChild == NULL)
		{
			if(f == p) f = p->LChild;
			else
			{
				if(f->key > p->key) f->RChild = p->LChild;
				else f->LChild = p->LChild;
			}
			free(p);
			return f;
		}
		else
		{
			q = p->RChild;
			s = q;
			ss = p;
			while(s->LChild != NULL) 
			{
				ss =s;
				s = s->LChild;
			}
			p->key = s->key;

			if(ss == s) ss = s->RChild;
			else
			{
				if(ss->key > s->key) ss->LChild = s->RChild;
				else ss->RChild = s->RChild;
			}
			free(s);

			return f;
		}
	}
}

void InTraverse(BiTreeNode *root)
{
	if(root == NULL) return;
	
	if(root->leftChild != NULL)
		InTraverse(root->leftChild);

	printf("%d   ", root->data);

	if(root->rightChild != NULL)
		InTraverse(root->rightChild);
}

void main(void)
{
	DataType test[] = {4,5,7,2,1,9,8,11,3,0}, x = 2;
	int n = 10, i;
	BiTreeNode *root = NULL, *p;

	root = Insert(root, test[0]);
	for(i = 1; i < n; i++)
	{
		Insert(root, test[i]);
	}
	InTraverse(root);
	Delete(root,root,4);
	InTraverse(root);
//printf("A");
	p = Search(root, 30);
//printf("B");
	if(p != NULL)
		printf("数据元素存在！");
	else
		printf("数据元素不存在！");

}

