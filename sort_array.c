#include <stdio.h>
void accept_array(short arr[], int length);
void selection_sort(short arr[], int length);
void print_array(short arr[], int length);
int main()
{
	int i;
	short arr[6];
	accept_array(arr, 6);
	selection_sort(arr,6);
	print_array(arr,6);
	return 0;
}
void accept_array(short arr[], int length)
{
	int i;
	printf("enter array element :\n");
	for(int i=0;i<length;i++)
	{
		printf("arr[%d]:",i);
		scanf("%hd",arr+i);
	}
}
void selection_sort(short arr[], int length)
{
	for(int i =0;i<length -1; i++)
	{
		for(int j=i+1;j<length;j++)
		{
			if(arr[i]<arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void print_array(short arr[], int length)
{
	printf("array :");
	for(int i = 0; i<length; i++)
	{
		printf("%-4d",arr[i]);
	}
	printf("\n");
}























