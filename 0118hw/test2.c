#include<stdio.h>

int sum_n();

int main()
{
	int i = 0;

	for(i; i < 10; i++)
	{
		if(i == 5)
			break;
	}
	printf("%d\n",i);
	
	sum_n();

	return 0;
}

int sum_n()
{	
	int n, j = 1;

	printf("请输入求和项数n:");
	
	scanf("%d", &n);
	
	if(n < 0)
		return 1;

	for(n; n > 1; n--)
		j += 2;

	printf("求和为%d\n", j);
}
