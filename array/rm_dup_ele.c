#include <stdio.h>
int main()
{
	int arr[20],i,j,k,size;
	printf("Define the no. of element in an array:\n");
	scanf("%d", &size);
	printf("\n enter %d element of an array: \n ", size);
	for(i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 0; i< size; i++)
	{
	   for(j = i+1; j<size; j++)
	   {
	   	if(arr[i] == arr[j])
		{
			for(k= j; k< size-1; k++)
			{
			  arr[k] = arr[k+1];
			 }
			  size--;
			  j--;
		}
	}
}
     printf (" \n Array elements after deletion of the duplicate elements:\n  ");
     for(i = 0; i< size; i++)
     {
     printf("%d\t",arr[i]);
    }
    return 0;
   }
