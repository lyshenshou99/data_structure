#include "SeqCQueue.h"							/*包括顺序循环队列*/

void DepthFSearch(AdjMWGraph G, int v, int visited[])
/*连通图G以v为初始顶点的深度优先遍历*/
/*数组visited标记了相应顶点是否已访问过，0表示未访问，1表示已访问*/
{
	int w;

	printf("%c   ", G.Vertices.list[v]);					/*输出顶点字母*/
	visited[v] = 1;

	w = GetFirstVex(G, v);
	while(w != -1)
	{
		if(! visited[w]) DepthFSearch(G, w, visited);
		w = GetNextVex(G, v, w);
	}
}

void DepthFirstSearch(AdjMWGraph G)
/*非连通图G的深度优先遍历*/
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
/*连通图G以v为初始顶点的广度优先遍历*/
/*数组visited标记了相应顶点是否已访问过，0表示未访问，1表示已访问*/
{
	DataType u, w;
	SeqCQueue queue;

	printf("%c   ", G.Vertices.list[v]);					/*输出顶点字母*/
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
				printf("%c   ", G.Vertices.list[w]);	/*输出顶点字母*/
				visited[w] = 1;
				QueueAppend(&queue, w);
			}
			w = GetNextVex(G, u, w);
		}
	}
}

void BroadFirstSearch(AdjMWGraph G)
/*非连通图G的广度优先遍历*/
{
	int i;
	int *visited = (int *)malloc(sizeof(int)*G.Vertices.size);

	for(i = 0; i < G.Vertices.size; i++)
		visited[i] = 0;

	for(i = 0; i < G.Vertices.size; i++)
		if(!visited[i]) BroadFSearch(G, i, visited);

	free(visited);
}
