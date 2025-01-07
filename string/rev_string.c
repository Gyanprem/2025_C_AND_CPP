#include<stdio.h>
#include<string.h>
int main()
{
	char str1[100],temp;
	int len,l,r,i;
	printf("enter a string to reverse: ");
	scanf("%[^\n]s",str1);
	len = strlen(str1);
	l = 0;
	r = len-1;
	for(i =0; i<r;i++)
	{
	temp =str1[i];
	str1[i]=str1[r];
	str1[r]=temp;
	r--;
	}
	printf("reverse %s\n",str1);
return 0;
}
