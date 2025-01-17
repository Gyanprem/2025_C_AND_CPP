#include<stdio.h>
int accept_arr(int a[][3],int b[][3]);
int add_arr(int a[][3],int b[][3]);
int sub_arr(int a[][3],int b[][3]);
int mult_arr(int a[][3],int b[][3]);

int a[3][3], b[3][3], c[3][3], n, i, j, k;
int main()
{
	printf("Enter the value of N (N <= 3): ");
	scanf("%d", & n);
	accept_arr(a,b);
	add_arr(a,b);
	sub_arr(a,b);
	mult_arr(a,b);
}
int accept_arr(int a[][3],int b[][3])
{

	printf("Enter the elements of Matrix-A: \n");
	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", & a[i][j]);
		}
	}

	printf("Enter the elements of Matrix-B: \n");
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++) 
		{
			scanf("%d", & b[i][j]);
		}
	}
}
int add_arr(int a[][3],int b[][3])
{

	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++) 
		{
			c[i][j] = 0;
			
			
				c[i][j] = a[i][j] + b[i][j];
			
		}
	}

	printf("The sum  of the two matrices is: \n");
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++) 
		{
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int sub_arr(int a[][3],int b[][3])
{

	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++) 
		{
			c[i][j] = 0;
		
				c[i][j] = a[i][j] - b[i][j];
		}		
      }

	printf("The subtraction  of the two matrices is: \n");
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++) 
		{
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int mult_arr(int a[][3],int b[][3])
{

	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++) 
		{
			c[i][j] = 0;
			for (k = 0; k < n; k++) 
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	printf("The product of the two matrices is: \n");
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++) 
		{
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}

