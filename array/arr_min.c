#include<stdio.h>
void accept_array(short arr[], int length);			
short find_min(short arr[],int length);
int main()
{
	int i;
        short arr[6];

	accept_array(arr, 6);

	printf("minimum element :%hd\n",find_min(arr, 6));

return 0;	 
}

void accept_array(short arr[], int length)
{
	printf("enter array element:\n");
	for(int i=0;i<length;i++)
	{
		printf("arr[%d]:",i);
		scanf("%hd",arr+i);
	}
}

short find_min(short arr[], int length)
{
	int min = arr[0];
	for(int i = 1 ; i < length ; i++)
	{
		if(arr[i] < min)
			min = arr[i];
	}
	return min;
}
