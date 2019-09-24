#include "SeqList.h"								/*包含顺序表头文件*/

typedef struct 
{
	SeqList Vertices;								/*存放顶点的顺序表*/
	int edge[MaxVertices][MaxVertices];				/*存放边的邻接矩阵*/
	int numOfEdges;									/*边的条数*/
}AdjMWGraph;										/*图的结构体定义*/

void Initiate(AdjMWGraph *G, int n)					/*初始化*/
{
	int i, j;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
		{
			if(i == j) G->edge[i][j] = 0;
			else G->edge[i][j] = MaxWeight;
		}

	G->numOfEdges = 0;							/*边的条数置为0*/
	ListInitiate(&G->Vertices);						/*顺序表初始化*/
}

void InsertVertex(AdjMWGraph *G, DataType vertex)
/*在图G中插入顶点vertex*/
{
	ListInsert(&G->Vertices, G->Vertices.size, vertex);	/*顺序表表尾插入*/
}

void InsertEdge(AdjMWGraph *G, int v1, int v2, int weight)
/*在图G中插入边<v1, v2>，边<v1, v2>的权为weight*/
{
	if(v1 < 0 || v1 > G->Vertices.size || v2 < 0 || v2 > G->Vertices.size)
	{
		printf("参数v1或v2越界出错!\n");
		exit(1);
	}

	G->edge[v1][v2] = weight;
	G->numOfEdges++;
}

void DeleteEdge(AdjMWGraph *G, int v1, int v2)
/*在图G中删除边<v1, v2>*/
{
	if(v1 < 0 || v1 > G->Vertices.size || v2 < 0 || v2 > G->Vertices.size || v1 == v2)
	{
		printf("参数v1或v2越界出错!\n");
		exit(1);
	}

	G->edge[v1][v2] = MaxWeight;
	G->numOfEdges--;
}

void DeleteVertex(AdjMWGraph *G, int v)
//删除结点v
{
	int n = ListLength(G->Vertices), i, j;
	DataType x;

	for(i = 0; i < n; i++)		
		for(j = 0; j < n; j++)
			if((i == v || j == v) && G->edge[i][j] > 0 && G->edge[i][j] < MaxWeight)
				G->numOfEdges--;					//被删除边计数

	for(i = v; i < n; i++)
		for(j = 0; j < n; j++)
			G->edge[i][j] = G->edge[i+1][j];		//删除第v行

	for(i = 0; i < n; i++)
		for(j = v; j < n; j++)
			G->edge[i][j] = G->edge[i][j+1];		//删除第v列
	
	ListDelete(&G->Vertices, v, &x);				//删除结点v
}

int GetFirstVex(AdjMWGraph G, int v)
/*在图G中寻找序号为v的顶点的第一个邻接顶点*/
/*如果这样的邻接顶点存在则返回该邻接顶点的序号，否则返回-1*/
{
	int col;

	if(v < 0 || v > G.Vertices.size)
	{
		printf("参数v1越界出错!\n");
		exit(1);
	}

	for(col = 0; col <= G.Vertices.size; col++)
		if(G.edge[v][col] > 0 && G.edge[v][col] < MaxWeight) return col;
	return -1;
}

int GetNextVex(AdjMWGraph G, int v1, int v2)
/*在图G中寻找v1顶点的邻接顶点v2的下一个邻接顶点*/
/*如果这样的邻接顶点存在则返回该邻接顶点的序号，否则返回-1*/
/*这里v1和v2都是相应顶点的序号*/
{
	int col;

	if(v1 < 0 || v1 > G.Vertices.size || v2 < 0 || v2 > G.Vertices.size)
	{
		printf("参数v1或v2越界出错!\n");
		exit(1);
	}

	for(col = v2+1; col <= G.Vertices.size; col++)
		if(G.edge[v1][col] > 0 && G.edge[v1][col] < MaxWeight) return col;
	return -1;
}
