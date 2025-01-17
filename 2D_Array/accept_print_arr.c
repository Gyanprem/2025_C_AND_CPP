#include <stdio.h>
void accept_array(int mat[3][3]);
void print_array(int mat[3][3]);
int main(void)
{
	int i,j;
	int mat[3][3];
	accept_array(mat);
	print_array(mat);
	return 0;
}
void accept_array(int mat[][3])
{
printf("enter 2d array :\n");
	for(int i = 0; i<3;i++)
	{
		for(int j= 0;j<3;j++)
		{
			printf("mat[%d][%d]: ",i,j);
			scanf("%d",&mat[i][j]);
		}
		printf("\n");
	}
}

void print_array(int mat[][3])
{
	printf("2d array: \n");
	for(int i = 0; i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%-4d",mat[i][j]);
		}
		printf("\n");
	}
}










