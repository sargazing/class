#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int **yanghui(int n);

int main()
{
	int n;
	int **str;

	scanf("%d", &n);
	str = yanghui(n);

	for(int i = 0; i < n; i++)
	{
		for(int j = n; j > 0; j--)
			printf(" ");
		for(int k = 0; k < 2 * n - 1; k++)
			printf("%2d", str[i][k]);
	printf("\n");
	}
}

int **yanghui(int n)
{
	if (n == 1)
	{
		int **str;
		str = malloc(sizeof(int *));
		*str = malloc(n * sizeof(int));
		**str = 1;
		return str;
	}
	if(n == 2)
	{
		int **str = yanghui(1);
//		str == realloc(str, sizeof(int *) * n);
//		str[1][0] = str[1][1] = 1;
		return str;
	}
	int **str;
	str = yanghui(n - 1);
	str == realloc(str, sizeof(int *) * n);
	str[n - 1][0] = str[n - 1][2 * n - 2] = 1;
	for(int i = 1; i < 2 * n - 2; i++)
		str[n - 1][i] = str[n - 2][i - 1] + str[n - 2][i];
	return str;
}
