#include <stdio.h>
void accept_array(short arr[], int length);
short find_max(short arr[], int length);
int main()
{
	int i;
	short arr[6];
	accept_array(arr,6);
	printf("maximum element : %hd\n", find_max(arr,6));
return 0;
}

void accept_array(short arr[], int length)
{
	printf("enter array element :\n");
	for(int i = 0; i<length; i++)
	{
		printf("arr[%d]:",i);
		scanf("%hd", arr+i);
	}
}
short find_max(short arr[], int length)
{
	int max = 0;
	for(int i = 0; i< length; i++)
	{
		if(arr[i] > max)
		
		max = arr[i];
		}
	return max;
}






