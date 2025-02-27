//c program print Pyramid pattern
#include <stdio.h>

int main()
{
	int row=4,space=3;
	//outer loop for number of rows
	for(int i = 1;i <=row;i++)
	{
		//inner loop for space printing
		for(int j=1;j<=space;j++)
		printf(" ");

		//inner loop for star printing
		for(int j = 1; j<=i;j++)
		printf("*");
		printf("\n");
		space--;
	}
	return 0;
}
