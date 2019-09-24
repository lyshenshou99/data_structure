#include "SeqCQueue.h"							/*����˳��ѭ������*/

void DepthFSearch(AdjMWGraph G, int v, int visited[])
/*��ͨͼG��vΪ��ʼ�����������ȱ���*/
/*����visited�������Ӧ�����Ƿ��ѷ��ʹ���0��ʾδ���ʣ�1��ʾ�ѷ���*/
{
	int w;

	printf("%c   ", G.Vertices.list[v]);					/*���������ĸ*/
	visited[v] = 1;

	w = GetFirstVex(G, v);
	while(w != -1)
	{
		if(! visited[w]) DepthFSearch(G, w, visited);
		w = GetNextVex(G, v, w);
	}
}

void DepthFirstSearch(AdjMWGraph G)
/*����ͨͼG��������ȱ���*/
{
	int i;
	int *visited = (int *)malloc(sizeof(int)*G.Vertices.size);

	for(i = 0; i < G.Vertices.size; i++)
		visited[i] = 0;

	for(i = 0; i < G.Vertices.size; i++)
		if(! visited[i]) DepthFSearch(G, i, visited);

	free(visited);
}

void BroadFSearch(AdjMWGraph G, int v, int visited[])
/*��ͨͼG��vΪ��ʼ����Ĺ�����ȱ���*/
/*����visited�������Ӧ�����Ƿ��ѷ��ʹ���0��ʾδ���ʣ�1��ʾ�ѷ���*/
{
	DataType u, w;
	SeqCQueue queue;

	printf("%c   ", G.Vertices.list[v]);					/*���������ĸ*/
	visited[v] = 1;

	QueueInitiate(&queue);
	QueueAppend(&queue, v);
	while(QueueNotEmpty(queue))
	{
		QueueDelete(&queue, &u);
		w = GetFirstVex(G, u);
		while(w != -1)
		{
			if(!visited[w])
			{
				printf("%c   ", G.Vertices.list[w]);	/*���������ĸ*/
				visited[w] = 1;
				QueueAppend(&queue, w);
			}
			w = GetNextVex(G, u, w);
		}
	}
}

void BroadFirstSearch(AdjMWGraph G)
/*����ͨͼG�Ĺ�����ȱ���*/
{
	int i;
	int *visited = (int *)malloc(sizeof(int)*G.Vertices.size);

	for(i = 0; i < G.Vertices.size; i++)
		visited[i] = 0;

	for(i = 0; i < G.Vertices.size; i++)
		if(!visited[i]) BroadFSearch(G, i, visited);

	free(visited);
}
