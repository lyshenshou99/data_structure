#include <stdio.h>
void towers(int n, char fromPeg, char toPeg, char auxPeg)
{
	if(n==1)									/*递归出口*/
	{
		printf("%s%c%s%c\n", "move disk 1 from peg ", 
			fromPeg, " to peg ", toPeg);
		return;
	} 

	/* 把n-1个圆盘从fromPeg借助toPeg移至auxPeg*/
	towers(n-1,fromPeg,auxPeg,toPeg);

	/*把圆盘n由fromPeg直接移至toPeg*/
	printf("%s%d%s%c%s%c\n", "move disk ", n, 
		" from peg ", fromPeg, " to peg ", toPeg);

	/*把n-1个圆盘从auxPeg借助fromPeg移至toPeg*/
	towers(n-1,auxPeg,toPeg,fromPeg);
}

void main(void)
{
	towers(4,'A', 'C', 'B');
}
