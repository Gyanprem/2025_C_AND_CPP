#include<stdio.h>
int binary_num(int);
int num,rem,arr[15],i=0,j;

int main(void)
{
	printf("enter decimal number");
	scanf("%d",&num);
	binary_num(num);
	return 0;
}
int binary_num(int num)
{
	while(num>0)
	{
		arr[i]=num%2;
		num=num/2;
		i++;
	}
	printf("binary number is\t ");
	for(j=i-1;j>=0;j--)
		printf("%d",arr[j]);
}
