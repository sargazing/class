//素数

#include<stdio.h>

#define TEN 10
int isprime(int num)
{
	int i;

	if(num == 1)
		return 1;
	else
	{
		for(i = 2; i <= num; i++)
		{	
	
			if(num % i == 0)
				break;
		}	
		if (i == num)
			return 1;
		else
			return 0;
	}	
}
int main(void)
{
	int num[TEN];
	for(int i = 0; i < TEN; i++)
	{
		LOOP:
			printf("请输入第个%d待判断整形数:", i + 1);

			scanf("%d", &num[i]);

			if(num[i] <= 0)
			{
				printf("不能判断负数或0\n");

				goto LOOP;
			}
			num[i] *= isprime(num[i]);
	}
	for(int j = 0; j < TEN; j++)
		if(num[j])
			printf("%d\n", num[j]);
	
	return 0;
}

