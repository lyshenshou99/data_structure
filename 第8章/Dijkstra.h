void Dijkstra(AdjMWGraph G, int v0, int distance[], int path[])
//��ȨͼG���±�v0���㵽�����������̾���distance�����·���±�path
{
	int n = G.Vertices.size;
	int *s = (int *)malloc(sizeof(int)*n);
	int minDis, i, j, u;

	//��ʼ�� 
	for(i = 0; i < n; i ++)								
	{
		distance[i] = G.edge[v0][i];
		s[i] = 0;
		if(i != v0 && distance[i] < MaxWeight) path[i] = v0;
		else path[i] = -1;
	}
	s[v0] = 1;       //��Ƕ���v0�ѴӼ���T���뵽����S�� 

	// �ڵ�ǰ��δ�ҵ����·���Ķ��㼯��ѡȡ������̾���Ķ���u 
	for(i = 1; i < n; i ++)
	{
		minDis = MaxWeight;
		for(j = 0;j <= n;j ++)
			if(s[j] == 0 && distance[j] < minDis)
			{
				u = j;
				minDis = distance[j];
			}
		//���Ѳ��ٴ���·��ʱ�㷨�����������Է���ͨͼ�Ǳ����
		if(minDis == MaxWeight) return;		

		s[u] = 1;     //��Ƕ���u�ѴӼ���T���뵽����S��
		//�޸Ĵ�v0�������������̾�������·��
		for(j = 0; j < n; j++)
			if(s[j] == 0 && G.edge[u][j] < MaxWeight && 
				distance[u] + G.edge[u][j] < distance[j])
			{
				//����v0������u�������������̾�������·��
				distance[j] = distance[u] + G.edge[u][j];
				path[j] = u;
			}
	}
}
