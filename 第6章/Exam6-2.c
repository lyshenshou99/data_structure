# include <stdio.h>
int BSearch(int a[], int x, int low, int high)
{
	int mid;

	if(low > high) return -1;

	mid = (low + high) / 2;
	if(x == a[mid])		return mid;
	else if(x < a[mid]) return BSearch(a, x, low, mid-1);
	else				return BSearch(a, x, mid+1, high);
}

main(void)
{
	int a[] = {1, 3, 4, 5, 17, 18, 31, 33};
	int x = 16;
	int bn;

	bn = BSearch(a, x, 0,7);
	if(bn == -1) printf("x不在数组a中");
	else printf("x在数组a的下标%d中", bn);
}
