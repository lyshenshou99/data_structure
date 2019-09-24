typedef struct 
{
	int row;								/*���±�*/
	int col;								/*���±�*/
	int weight;							/*Ȩֵ*/
}RowColWeight;							/*����Ϣ��Ԫ��ṹ�嶨��*/

void CreatGraph(AdjMWGraph *G, DataType V[], int n, RowColWeight E[], int e)
/*��ͼG�в���n��������ϢV��e������ϢE*/
{
	int i, k;

	Initiate(G, n);							/*����˳����ʼ��*/

	for(i = 0; i < n; i++)
		InsertVertex(G, V[i]);				/*�������*/

	for(k = 0; k < e; k++)
		InsertEdge(G, E[k].row, E[k].col, E[k].weight);		/*�߲���*/
}
