#include<stdio.h>

int main()
{
	int num, i = 0;

	for(num = 100; num < 1000; num++)
	{
		if((num / 100) * (num / 100) * (num / 100) + (num % 10) * \
			(num % 10) * (num % 10) + (num / 10 % 10) * (num / 10 % 10)\
			*(num / 10 % 10) == num)
			i++;
	}
	printf("共%d个水仙花数", i);
}
