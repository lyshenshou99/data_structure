#include <stdio.h>
void towers(int n, char fromPeg, char toPeg, char auxPeg)
{
	if(n==1)									/*�ݹ����*/
	{
		printf("%s%c%s%c\n", "move disk 1 from peg ", 
			fromPeg, " to peg ", toPeg);
		return;
	} 

	/* ��n-1��Բ�̴�fromPeg����toPeg����auxPeg*/
	towers(n-1,fromPeg,auxPeg,toPeg);

	/*��Բ��n��fromPegֱ������toPeg*/
	printf("%s%d%s%c%s%c\n", "move disk ", n, 
		" from peg ", fromPeg, " to peg ", toPeg);

	/*��n-1��Բ�̴�auxPeg����fromPeg����toPeg*/
	towers(n-1,auxPeg,toPeg,fromPeg);
}

void main(void)
{
	towers(4,'A', 'C', 'B');
}
