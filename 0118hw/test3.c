#include<stdio.h>

int main()
{
	int num, num_s = 0;

	printf("请输入一个整数：");

	scanf("%d",&num);

	for(num; num > 0; num /= 10)
		num_s = num % 10 + num_s * 10;
	
	printf("逆序数为%d\n", num_s);
}
