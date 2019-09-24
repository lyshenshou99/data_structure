#include <stdlib.h>
#include <stdio.h>

typedef struct						/*路口的结构体定义*/
{
	int left;							/*向左*/
	int forward;						/*向前*/
	int right;							/*向右*/
} InterSection;

typedef struct						/*迷宫的结构体定义*/
{
	int mazeSize;					/*路口个数*/
	int Exit;						/*出口*/
	InterSection *intSec;			/*路口集合*/
} Maze;

void CreatMaze(char *filename, Maze *m)
/*按文件Filename中存放的数据创建迷宫m*/
{
	FILE *fp;		
	int i;

	fp = fopen(filename, "r");			/*打开文件*/
	if(!fp)
	{
		printf("数据文件无法打开!");
		return;
	}

	fscanf(fp, "%d", &m->mazeSize);			/*读入路口个数*/
	m->intSec = (InterSection *)malloc
		(sizeof(InterSection)*(m->mazeSize+1));	/*建立mazeSize+1个元素的数组*/

	for(i = 1; i <= m->mazeSize; i++)		/*读入全部路口的结构体数值*/
		fscanf(fp, "%d%d%d", &m->intSec[i].left, &m->intSec[i].forward, &m->intSec[i].right);
	fscanf(fp, "%d%d%d", &m->Exit);			/*读入出口数值*/

	close(fp);							/*关闭文件*/
}

/*用回溯法搜索迷宫的所有分支，输入参数currSetValue为当前所处的路口*/ 
int TravMaze(Maze *m, int currSetValue)
{
	/* currSetValue>0为有路径存在，可以继续探索发现一条路径*/
	if(currSetValue > 0)
	{
		if(currSetValue == m->Exit)							/*到达出口*/
		{
			printf("%d  <== ", currSetValue);				/*输出路口号*/
			return 1;									
		}

		else if(TravMaze(m, m->intSec[currSetValue].left) == 1)		/*向左探索*/
		{
			/*只有探索成功，即返回值为1，才执行以下语句*/
			printf("%d  <== ", currSetValue);				/*输出路口号*/
			return 1;									
		
		}
		else if(TravMaze(m, m->intSec[currSetValue].forward) == 1)	/*向前探索*/
		{
			printf("%d  <== ", currSetValue);				/*输出路口号*/
			return 1;
		
		}
		else if(TravMaze(m, m->intSec[currSetValue].right) == 1)	/*向右探索*/
		{
			printf("%d  <== ", currSetValue);				/*输出路口号*/
			return 1;
		
		}
	}
	/* currSetValue=0为无路径存在，返回0*/
	return 0;				
}

void main(void)
{
	Maze m;
	int start = 1;

	CreatMaze("Maze1.dat", &m);
	if(TravMaze(&m, start))
		printf("\n此迷宫的一条通路如上所示！");
	else
		printf("\n此迷宫无通路!");
}
