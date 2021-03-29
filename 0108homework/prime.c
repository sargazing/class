//枚举100～999内所有素数

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
	for(int cm = 100; cm <1000; cm++)  
	{
		if(isprime(cm) == 1)
			printf("%5d", cm);
	}
	printf("\n");
}

