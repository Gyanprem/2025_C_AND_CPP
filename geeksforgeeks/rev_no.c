#include <stdio.h>

int reverse(int n, int ans)
{
	if(n == 0)
		return ans;
		ans = ans * 10 + n % 10;
		return reverse(n /10,ans);
}

int main()
{
	int N = 15942;
	printf("initial number : %d\n", N);
	int ans = 0;
	ans = reverse(N, ans);
	printf("%d after again revrse using recussion",ans);
	return 0;
}
