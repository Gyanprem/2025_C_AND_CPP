#include <stdio.h>
void accept_array(short arr[], int length);
void rev_array(short arr[], int length);
void print_array(short arr[], int length);
int main()
{
	int i;
	short arr[6];
	accept_array(arr, 6);
	rev_array(arr , 6);
	print_array(arr, 6);
	return 0;
}
void accept_array(short arr[], int length)
{
	printf("enter array element :\n");
 	for(int i = 0; i<length; i++)
	{
		printf("arr[%d]:",i);
		scanf("%hd",arr+i);
	}
}

void rev_array(short arr[6], int length)
{
	int temp, j;
	for(int i = 0, j = length-1; i<j; i++,j--)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
void print_array(short arr[], int length)
{
	printf("Array");
	for(int i= 0; i< length; i++)
	{
		printf("%-4hd", arr[i]);
	}
	printf("\n");
}














