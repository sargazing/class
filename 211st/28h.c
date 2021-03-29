//28
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define N 20
#define SWAP(x, y) typeof(x) z; z = x ; x = y; y = z;

int main()
{
	int arr[N];

	srand(getpid());

	for(int i = 0; i < N; i++)
	{
		do{
			arr[i] = rand() % 100;
		}while(arr[i] < 10);
	}
	
	int max;
	for(int i = 0; i < N - 1; i++)
	{
		max = i;
		for(int j = i + 1; j < N ; j++)
		{
			max = arr[max] > arr[j]? max : j;
		}
		SWAP(arr[max], arr[i]);
	}
	for(int j = 0; j < N; j++)
		printf("%4d", arr[j]);

	printf("\n");

	return 0;
}
