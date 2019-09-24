#include <stdlib.h>
#include <stdio.h>

typedef struct						/*·�ڵĽṹ�嶨��*/
{
	int left;							/*����*/
	int forward;						/*��ǰ*/
	int right;							/*����*/
} InterSection;

typedef struct						/*�Թ��Ľṹ�嶨��*/
{
	int mazeSize;					/*·�ڸ���*/
	int Exit;						/*����*/
	InterSection *intSec;			/*·�ڼ���*/
} Maze;

void CreatMaze(char *filename, Maze *m)
/*���ļ�Filename�д�ŵ����ݴ����Թ�m*/
{
	FILE *fp;		
	int i;

	fp = fopen(filename, "r");			/*���ļ�*/
	if(!fp)
	{
		printf("�����ļ��޷���!");
		return;
	}

	fscanf(fp, "%d", &m->mazeSize);			/*����·�ڸ���*/
	m->intSec = (InterSection *)malloc
		(sizeof(InterSection)*(m->mazeSize+1));	/*����mazeSize+1��Ԫ�ص�����*/

	for(i = 1; i <= m->mazeSize; i++)		/*����ȫ��·�ڵĽṹ����ֵ*/
		fscanf(fp, "%d%d%d", &m->intSec[i].left, &m->intSec[i].forward, &m->intSec[i].right);
	fscanf(fp, "%d%d%d", &m->Exit);			/*���������ֵ*/

	close(fp);							/*�ر��ļ�*/
}

/*�û��ݷ������Թ������з�֧���������currSetValueΪ��ǰ������·��*/ 
int TravMaze(Maze *m, int currSetValue)
{
	/* currSetValue>0Ϊ��·�����ڣ����Լ���̽������һ��·��*/
	if(currSetValue > 0)
	{
		if(currSetValue == m->Exit)							/*�������*/
		{
			printf("%d  <== ", currSetValue);				/*���·�ں�*/
			return 1;									
		}

		else if(TravMaze(m, m->intSec[currSetValue].left) == 1)		/*����̽��*/
		{
			/*ֻ��̽���ɹ���������ֵΪ1����ִ���������*/
			printf("%d  <== ", currSetValue);				/*���·�ں�*/
			return 1;									
		
		}
		else if(TravMaze(m, m->intSec[currSetValue].forward) == 1)	/*��ǰ̽��*/
		{
			printf("%d  <== ", currSetValue);				/*���·�ں�*/
			return 1;
		
		}
		else if(TravMaze(m, m->intSec[currSetValue].right) == 1)	/*����̽��*/
		{
			printf("%d  <== ", currSetValue);				/*���·�ں�*/
			return 1;
		
		}
	}
	/* currSetValue=0Ϊ��·�����ڣ�����0*/
	return 0;				
}

void main(void)
{
	Maze m;
	int start = 1;

	CreatMaze("Maze1.dat", &m);
	if(TravMaze(&m, start))
		printf("\n���Թ���һ��ͨ·������ʾ��");
	else
		printf("\n���Թ���ͨ·!");
}
