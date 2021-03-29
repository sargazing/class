//39
#include<stdio.h>

#define N 8

int main()
{
	int arr[N] = {1, 4, 80, 23 , 76, 14, 52};
	int num;

	int t, j;
	for(int i = 1; i < N; i++)
	{
		t = arr[i];
		for(j = i - 1; j >= 0; j--)
		{
			if(arr[j] < t)
			{
				arr[j + 1] = arr[j];
			}
			else
				break;
		}
		arr[j + 1] = t;	
	}
	for(j = 0; j < N - 1; j++)
		printf("%3d", arr[j]);
	
	printf("\n");
	
	printf("请输入插入数组的整形数：");

	scanf("%d", &num);

	for(j = N - 2; j >= 0; j--)
	{
		if(arr[j] < num)
			arr[j + 1] = arr[j];
		else 
			break;
	}
	arr[j + 1] = num; 

	for(j = 0; j < N; j++)
		printf("%3d", arr[j]);
	
	printf("\n");

	return 0;
}
