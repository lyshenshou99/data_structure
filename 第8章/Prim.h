void Prim(AdjMWGraph G)
/*������ķ����������G����С������closeVertex */
{
	int n = G.Vertices.size, minCost;
	int *lowCost = (int *)malloc(sizeof(int)*n);
	int i, j, k;

	 
	/*�����Ϊ0�Ķ������������С������*/
	printf("����ֵ = %c\n", G.Vertices.list[0]);
	for(i = 1; i < n; i ++)	
		lowCost[i] = G.edge[0][i];
	lowCost[0] = -1;


	for(i = 1;i < n;i++) 
	{
		/*Ѱ�ҵ�ǰ��СȨֵ�ıߵĶ��� */
		minCost = MaxWeight;			/*MaxWeightΪ��������Ȩֵ */
		j = 1; 
		k = 1;
		while(j < n)
		{
			if(lowCost[j] < minCost && lowCost[j] != -1)
			{
				minCost = lowCost[j];
				k = j;
			}
			j ++;
		}
		printf("����ֵ = %c  �ߵ�Ȩֵ = %d\n", G.Vertices.list[k], minCost);
		lowCost[k] = -1;

		/*�޸ĵ����������·��ֵ*/
		for(j = 1; j < n; j++)
		{ 
			if(G.edge[k][j] < lowCost[j])
				lowCost[j] = G.edge[k][j];
		}
	}
	free(lowCost);
}
