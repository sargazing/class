#include<stdio.h>

int yanghui(int i, int j);

int main()
{
	int n;

	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	{
		for(int k = n; k > i; k--)
			printf("  ");
		for(int j = 1; j <= i; j++)
			printf("%4d", yanghui(i, j));
		printf("\n");
	}
}

int yanghui(int i, int j)
{
	if(j > i || j < 1 || i < 1)
		return 0;
	if(j == 1 || j == i)
		return 1;
	int num;
	num = yanghui(i - 1, j - 1) + yanghui(i - 1, j);
	return num;
}
