//素数

#include<stdio.h>

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
	int num;

	printf("请输入待判断整形数:");

	scanf("%d", &num);

	if(num <= 0)
	{
		printf("不能判断负数或0\n");

		return 1;
	}

	if(isprime(num))
		printf("%d是素数\n", num);
	else
		printf("%d非素数\n", num);	
}

