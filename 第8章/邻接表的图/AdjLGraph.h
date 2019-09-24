typedef struct Node
{
	int dest;
	struct Node *next;
} Edge;

typedef struct
{
	DataType data;
	int sorce;
	Edge *adj;
} AdjLHeight;

typedef struct
{
	AdjLHeight a[MaxVertices];
	int numOfVerts;
	int numOfEdges;
} AdjLGraph;


AdjInitiate(AdjLGraph *G)
{
	int i;

	G->numOfVerts = 0;
	G->numOfEdges = 0;
	for(i = 0; i < MaxVertices; i++)
	{
		G->a[i].sorce = i;
		G->a[i].adj = NULL;
	}
}

AdjDestroy(AdjLGraph *G)
{
	int i;
	Edge *p, *q;

	for(i = 0; i < G->numOfVerts; i++)
	{
		p = G->a[i].adj;
		while(p != NULL)
		{
			q = p->next;
			free(p);
			p = q;
		}
	}
}

void InsertVertex(AdjLGraph *G, int i, DataType vertex)
{
	if(i >= 0 && i < MaxVertices)
	{
		G->a[i].data = vertex;
		G->numOfVerts++;
	}
	else printf("顶点越界");
}

void InsertEdge(AdjLGraph *G, int v1, int v2)
{
	Edge *p;
	
	if(v1 < 0 || v1 >= G->numOfVerts || v2 < 0 || v2 >= G->numOfVerts)
	{
		printf("参数v1或v2越界出错!");
		exit(0);
	}

	p = (Edge *)malloc(sizeof(Edge));
	p->dest = v2;

	p->next = G->a[v1].adj;
	G->a[v1].adj = p;

	G->numOfEdges++;
}

void DeleteEdge(AdjLGraph *G, int v1, int v2)
{
	Edge *curr, *pre;

	if(v1 < 0 || v1 >= G->numOfVerts || v2 < 0 || v2 >= G->numOfVerts)
	{
		printf("参数v1或v2越界出错!");
		exit(0);
	}

	pre = NULL;
	curr = G->a[v1].adj;
	while(curr != NULL && curr->dest != v2)
	{
		pre = curr; 
		curr = curr->next;
	}

	if(curr != NULL && curr->dest == v2 && pre == NULL) 
	{
		G->a[v1].adj = curr->next;
		free(curr);
		G->numOfEdges--;
	}
	else if(curr != NULL && curr->dest == v2 && pre != NULL)
	{
		pre->next = curr->next;
		free(curr);
		G->numOfEdges--;
	}
	else
		printf("边<v1, v2>不存在!"); 
}

int GetFirstVex(AdjLGraph G, int v)
{
	Edge *p;

	if(v < 0 || v > G.numOfVerts)
	{
		printf("参数v1或v2越界出错!");
		exit(0);
	}

	p = G.a[v].adj;
	if(p != NULL) return p->dest;
	else return -1;
}

int GetNextVex(AdjLGraph G, int v1, const int v2)
{
	Edge *p;

	if(v1 < 0 || v1 > G.numOfVerts || v2 < 0 || v2 > G.numOfVerts)
	{
		printf("参数v1或v2越界出错!");
		exit(0);
	}

	p = G.a[v1].adj;
	while(p != NULL)
	{
		if(p->dest != v2)
		{
			p = p->next;
			continue;
		}
		else break;
	}
	
	p = p->next;
	if(p !=NULL) return  p->dest;
	else return -1;
}
