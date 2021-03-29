#include<stdio.h>

int main()
{
	int n;

	printf("请输入元素个数：");

	scanf("%d", &n);

	if(n > 9 || n < 2) 
	{
	printf("输入格式错误\n");

	return 0;
	}

	int a[n];
	int num = 9;
	int sum = 0;
	int i = 0;
//	while(1)
	for(int i = 0; i < n; i++)
	{
		scanf("%d ",&num);

		
		a[i] = num;

		char c = getchar();
		if(c == '\n')
			break;

	}
	
				for(int j = 0 ; j < n; j++)

					printf("%4d", a[j]);
		
			//for(k = 0; k <= n - 2; k++)
		//	{
			//	sum = 2;
				//sum += a[k] * 10 + a[n - 1] + a[n - 1] * 10 + a[k];
		//	}

		//	printf("		%d\n", sum);
	/*
	for(int j = 0; j <= n - 1; j++)//元素0～n - 1
	{
		for(a[j]; a[j] > j;a[j]--)//a[j]~j
		{
			for(int k = 0; k <= n - 2; k++)
			{
				sum += a[k] * 10 + a[n - 1] + a[n - 1] * 10 + a[k];
			}
			if(a[j] == num + 1 && j == 0 && sum < 330)
			{
				printf("%d个元素的数组无法重组计算得到330\n", n);

				return 0;
			}
			if(sum == 330)
			{
				for(n; n >= 0; n--)
					printf("%4d", a[n]);
				return 0;
			}	
		}
	}
	printf("%d个元素的数组无法重组计算得到330\n", n);

	return 0;
*/
}
