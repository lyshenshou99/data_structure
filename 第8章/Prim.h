void Prim(AdjMWGraph G)
/*用普里姆方法建立网G的最小生成树closeVertex */
{
	int n = G.Vertices.size, minCost;
	int *lowCost = (int *)malloc(sizeof(int)*n);
	int i, j, k;

	 
	/*从序号为0的顶点出发构造最小生成树*/
	printf("顶点值 = %c\n", G.Vertices.list[0]);
	for(i = 1; i < n; i ++)	
		lowCost[i] = G.edge[0][i];
	lowCost[0] = -1;


	for(i = 1;i < n;i++) 
	{
		/*寻找当前最小权值的边的顶点 */
		minCost = MaxWeight;			/*MaxWeight为定义的最大权值 */
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
		printf("顶点值 = %c  边的权值 = %d\n", G.Vertices.list[k], minCost);
		lowCost[k] = -1;

		/*修改到其它顶点的路径值*/
		for(j = 1; j < n; j++)
		{ 
			if(G.edge[k][j] < lowCost[j])
				lowCost[j] = G.edge[k][j];
		}
	}
	free(lowCost);
}
