//15
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define N 100

int main()
{
	int arr[N];
	int count = 0;
	
	srand(getpid());

	for(int i = 0; i < N; i ++)
	{
		do{
		arr[i] = rand() % 1000;
		}while(arr[i] < 100);
	}
	for(int j = 0; j < N; j++)
	{
		printf("%4d", arr[j]);

		if(j % 10 == 9)
			printf("\n");
	}
	printf("\n其中同时为3、 5、 7的倍数的元素有：\n");

	
	for(int j = 0; j < N; j++)
	{
		if(arr[j] % 5 || arr[j] % 7 || arr[j] % 3)
			continue;
		
		printf("%4d", arr[j]);

		count++;
	}
	if(count == 0)
			printf("0个");

	printf("\n");

	return 0;
}
