//枚举指令范围内的完数
#include<stdio.h>

int main()
{
	int max, num, sum;
LOOP:
	printf("请输入搜寻范围:");

	scanf("%d", &max);

	if(max == 0)
	{
		printf("范围不能为0\n");

		goto LOOP;
	}
	for(num = 1; num <= max; num++)
	{
		sum = 0;

		for(int i = 1; i < num; i++)
		{
			if(num % i == 0)
				sum += i;
		}
		if(sum == num)
			printf("%d是完数\n", num);
	}
}
