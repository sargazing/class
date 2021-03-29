//3
#include<stdio.h>

#define N 20

int main()
{
	int num[N];
	int sum = 0;
	int number = 20;

	printf("请输入20整形个数：");

	for(int i = 0; i < N; i++)
	{
		scanf("%d", num + i);
	
		if(num[i] < 0)
		{
			num[i] = 0;

			number--;
		}
		sum += num [i];

	}

	printf("共%d个正数，和为%d\n", number, sum);
	
	return 0;
}

