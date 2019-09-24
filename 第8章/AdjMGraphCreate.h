typedef struct 
{
	int row;								/*行下标*/
	int col;								/*列下标*/
	int weight;							/*权值*/
}RowColWeight;							/*边信息三元组结构体定义*/

void CreatGraph(AdjMWGraph *G, DataType V[], int n, RowColWeight E[], int e)
/*在图G中插入n个顶点信息V和e条边信息E*/
{
	int i, k;

	Initiate(G, n);							/*顶点顺序表初始化*/

	for(i = 0; i < n; i++)
		InsertVertex(G, V[i]);				/*顶点插入*/

	for(k = 0; k < e; k++)
		InsertEdge(G, E[k].row, E[k].col, E[k].weight);		/*边插入*/
}
