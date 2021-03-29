#include<stdio.h>

#define  N 10

int main()
{
	int arr[N][N] = {0};

	for(int i = 0; i < N; i++)
		arr[i][0] = arr[i][i]= 1;
	
	for(int j = 2; j < N; j++)
		for(int k = 1; k < j; k++)
			arr[j][k] = arr[j - 1][k - 1] + arr[j - 1][k];

	for(int k = 0; k < N; k++)
	{	
		for(int i = 0; i < N - k; i++)
			printf("  ");

		for(int j = 0; j < k + 1; j++)
		{
			printf("%4d", arr[k][j]);
		}
		printf("\n");
	}
}
