#include "SeqList.h"								/*����˳���ͷ�ļ�*/

typedef struct 
{
	SeqList Vertices;								/*��Ŷ����˳���*/
	int edge[MaxVertices][MaxVertices];				/*��űߵ��ڽӾ���*/
	int numOfEdges;									/*�ߵ�����*/
}AdjMWGraph;										/*ͼ�Ľṹ�嶨��*/

void Initiate(AdjMWGraph *G, int n)					/*��ʼ��*/
{
	int i, j;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
		{
			if(i == j) G->edge[i][j] = 0;
			else G->edge[i][j] = MaxWeight;
		}

	G->numOfEdges = 0;							/*�ߵ�������Ϊ0*/
	ListInitiate(&G->Vertices);						/*˳����ʼ��*/
}

void InsertVertex(AdjMWGraph *G, DataType vertex)
/*��ͼG�в��붥��vertex*/
{
	ListInsert(&G->Vertices, G->Vertices.size, vertex);	/*˳����β����*/
}

void InsertEdge(AdjMWGraph *G, int v1, int v2, int weight)
/*��ͼG�в����<v1, v2>����<v1, v2>��ȨΪweight*/
{
	if(v1 < 0 || v1 > G->Vertices.size || v2 < 0 || v2 > G->Vertices.size)
	{
		printf("����v1��v2Խ�����!\n");
		exit(1);
	}

	G->edge[v1][v2] = weight;
	G->numOfEdges++;
}

void DeleteEdge(AdjMWGraph *G, int v1, int v2)
/*��ͼG��ɾ����<v1, v2>*/
{
	if(v1 < 0 || v1 > G->Vertices.size || v2 < 0 || v2 > G->Vertices.size || v1 == v2)
	{
		printf("����v1��v2Խ�����!\n");
		exit(1);
	}

	G->edge[v1][v2] = MaxWeight;
	G->numOfEdges--;
}

void DeleteVertex(AdjMWGraph *G, int v)
//ɾ�����v
{
	int n = ListLength(G->Vertices), i, j;
	DataType x;

	for(i = 0; i < n; i++)		
		for(j = 0; j < n; j++)
			if((i == v || j == v) && G->edge[i][j] > 0 && G->edge[i][j] < MaxWeight)
				G->numOfEdges--;					//��ɾ���߼���

	for(i = v; i < n; i++)
		for(j = 0; j < n; j++)
			G->edge[i][j] = G->edge[i+1][j];		//ɾ����v��

	for(i = 0; i < n; i++)
		for(j = v; j < n; j++)
			G->edge[i][j] = G->edge[i][j+1];		//ɾ����v��
	
	ListDelete(&G->Vertices, v, &x);				//ɾ�����v
}

int GetFirstVex(AdjMWGraph G, int v)
/*��ͼG��Ѱ�����Ϊv�Ķ���ĵ�һ���ڽӶ���*/
/*����������ڽӶ�������򷵻ظ��ڽӶ������ţ����򷵻�-1*/
{
	int col;

	if(v < 0 || v > G.Vertices.size)
	{
		printf("����v1Խ�����!\n");
		exit(1);
	}

	for(col = 0; col <= G.Vertices.size; col++)
		if(G.edge[v][col] > 0 && G.edge[v][col] < MaxWeight) return col;
	return -1;
}

int GetNextVex(AdjMWGraph G, int v1, int v2)
/*��ͼG��Ѱ��v1������ڽӶ���v2����һ���ڽӶ���*/
/*����������ڽӶ�������򷵻ظ��ڽӶ������ţ����򷵻�-1*/
/*����v1��v2������Ӧ��������*/
{
	int col;

	if(v1 < 0 || v1 > G.Vertices.size || v2 < 0 || v2 > G.Vertices.size)
	{
		printf("����v1��v2Խ�����!\n");
		exit(1);
	}

	for(col = v2+1; col <= G.Vertices.size; col++)
		if(G.edge[v1][col] > 0 && G.edge[v1][col] < MaxWeight) return col;
	return -1;
}
