void Dijkstra(AdjMWGraph G, int v0, int distance[], int path[])
//带权图G从下标v0顶点到其它顶点的最短距离distance和最短路径下标path
{
	int n = G.Vertices.size;
	int *s = (int *)malloc(sizeof(int)*n);
	int minDis, i, j, u;

	//初始化 
	for(i = 0; i < n; i ++)								
	{
		distance[i] = G.edge[v0][i];
		s[i] = 0;
		if(i != v0 && distance[i] < MaxWeight) path[i] = v0;
		else path[i] = -1;
	}
	s[v0] = 1;       //标记顶点v0已从集合T加入到集合S中 

	// 在当前还未找到最短路径的顶点集中选取具有最短距离的顶点u 
	for(i = 1; i < n; i ++)
	{
		minDis = MaxWeight;
		for(j = 0;j <= n;j ++)
			if(s[j] == 0 && distance[j] < minDis)
			{
				u = j;
				minDis = distance[j];
			}
		//当已不再存在路径时算法结束；此语句对非连通图是必须的
		if(minDis == MaxWeight) return;		

		s[u] = 1;     //标记顶点u已从集合T加入到集合S中
		//修改从v0到其它顶点的最短距离和最短路径
		for(j = 0; j < n; j++)
			if(s[j] == 0 && G.edge[u][j] < MaxWeight && 
				distance[u] + G.edge[u][j] < distance[j])
			{
				//顶点v0经顶点u到其它顶点的最短距离和最短路径
				distance[j] = distance[u] + G.edge[u][j];
				path[j] = u;
			}
	}
}
