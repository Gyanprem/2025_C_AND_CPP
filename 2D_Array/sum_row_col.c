#include <stdio.h>
int main()
{
	int m, n;
	printf("enter the required number of rows and columns:\n");
	scanf("%d %d", &m, &n);
	int arr[m][n];
	printf("enter the elements of the given matrix:\n");
	for(int i = 0; i<m; i++)
	{
		for(int j = 0; j<n; j++)
		{
		  scanf("%d", &arr[i][j]);
		 }
	}
	printf("\n The elements in the matrix are \n");
	for(int i = 0; i<m; i++)
	{
		for(int j = 0; j<n; j++)
		{
		printf("%d",arr[i][j]);
	}
	printf("\n");

	}
	printf("\n calculation of row sum \n");
	for(int i = 0; i<m; i++)
	{
	   int  rowsum = 0;
	   for(int j=0; j<n; j++)
	   {
	    rowsum = rowsum + arr[i][j];
	    }
	    printf("\n sum of the elements in row  %d is %d \n", i, rowsum);
	    }
	    printf("\n calculation of column sum \n");
	    for(int i= 0; i<m; i++)
	    {
	    	int colsum = 0;
		for(int j = 0; j<n; j++)
		{
			colsum = colsum +arr[j][i];;
		}
		printf("\n the sum of all the element in column  %d is %d\n", i, colsum);
		}
		return 0;
		}





	




