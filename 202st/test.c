#include<stdio.h>

int mysum(int n);
int myproduck(int n);

int main()
{
	int n;
	
	scanf("%d", &n);
	
	printf("%d\n", mysum(n));
}

int mysum(int n)
{
//	int i, j;

	if(n <= 0)
		return 0;

	if(n == 1)
		return 1;

//	for(i = j = 1; i <= n; i++)
//	{
//		j = j * i;
//	}
	return myproduck(n) + mysum(n - 1);
}
int myproduck(int n)
{
	if(n == 1)
		return 1;
	return n * myproduck(n - 1);
}
