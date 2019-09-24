#include <stdio.h>

typedef struct
{
	int retAddr;
	int nPara;
	char fromPegPara;
	char toPegPara;
	char auxPegPara;
}DataType;
#define MaxStackSize 100
#include "SeqStack.h"

void SimTowers (int n, char fromPeg, char toPeg, char auxPeg);

main()
{
   SimTowers(4,'X','Z','Y');
}

void SimTowers (int n, char fromPeg, char toPeg, char auxPeg)
/*把n个盘子从fromPeg柱借助auxPeg柱移到toPeg柱*/
{
	DataType  currarea;
	SeqStack  s;
	char      temp;
	int i;

	StackInitiate(&s);					/*堆栈初始化*/

	/*当前工作区初始化*/	
	currarea.nPara    = n;
	currarea.fromPegPara = fromPeg;
	currarea.toPegPara   = toPeg;
	currarea.auxPegPara  = auxPeg;
	currarea.retAddr   = 1;
	StackPush(&s, currarea);			/*进栈*/

	/*以下模拟出口*/
start:
	if(currarea.nPara==1)
	{
		printf("\n%s%c%s%c","move disk 1 from peg ", currarea.fromPegPara,
				" to.peg ", currarea.toPegPara);
		i=currarea.retAddr;
		StackPop(&s, &currarea);
		switch(i)
		{
			case 1: goto lable11;
			case 2: goto lable12;
			case 3: goto lable13;
		}
	}

	/*以下模拟递归自调用过程*/
	StackPush(&s,currarea);

	currarea.nPara   --;
	temp              = currarea.auxPegPara;
	currarea.auxPegPara = currarea.toPegPara;
	currarea.toPegPara  = temp;
	currarea.retAddr  = 2;

	goto start;

	/*以下模拟返回第一次递归调用*/
lable12:
	printf("\n%s%d%s%c%s%c","move disk ",
			currarea.nPara," from peg ",
			currarea.fromPegPara, " to peg ",
			currarea.toPegPara);
	StackPush(&s,currarea);

	currarea.nPara    --;
	temp               = currarea.fromPegPara;
	currarea.fromPegPara = currarea.auxPegPara;
	currarea.auxPegPara  = temp;
	currarea.retAddr   = 3;

	goto start;

	/*以下模拟返回第二次递归调用*/
lable13:
	i=currarea.retAddr;
	StackPop(&s, &currarea);
	switch(i)
	{
		case 1: goto lable11;
		case 2: goto lable12;
		case 3: goto lable13;
	}

	/*以下模拟返回主调函数*/
lable11:
	return;
}
