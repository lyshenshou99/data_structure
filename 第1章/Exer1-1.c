#include <stdio.h>

void main(void)
{

	int n = 3;
	int x = n;			/* n > 1 */
	int t = 0;
	int y = 0;
	while(x >= (y+1)*(y+1))
	{
		y++;
		t++;
	}

	
	
/*	
	int i, j, k, x = 0, n = 100;
	for (i = 0; i < n; i++)
		for (j = 0; j < i; j++)
			for (k = 0; k < j; k++)
			{
				x = x + 2;
				t++;
			}
*/
	printf("t = %d", t);
}