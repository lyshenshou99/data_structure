#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include"DString.h"

void main(void)
{
	DString	myString1, myString2, myString3;
	int i, max1 = 10, max2 = 20, max3 = 10;
		
	Initiate(&myString1, max1, "Data ");
	Initiate(&myString2, max2, "Structure");
	Initiate(&myString3, max3, "");

	Insert(&myString2, 0, myString1);
	for(i = 0; i < myString2.length; i++)
		printf("%c", myString2.str[i]);
	printf("\n");

	Delete(&myString2, 0, 5);
	for(i = 0; i < myString2.length; i++)
		printf("%c", myString2.str[i]);
	printf("\n");

	SubString(&myString2, 0, 5, &myString3);
	for(i = 0; i < myString3.length; i++)
		printf("%c", myString3.str[i]);
	printf("\n");

	Destroy(&myString1);
	Destroy(&myString2);
}