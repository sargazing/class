#include<stdio.h>

int main()
{
	int num, i = 0;

	printf("请输入一个四位整形数：");

	scanf("%d", &num);

	if(num < 0 || num > 9999)
	{
		printf("error\n");

		return 1;
	}

	for(int j = 1; j <= 10000; j *= 10)
	{
		if(num / j % 10 == num / 10 % 10)
			i++;
	}
	printf("%d的十位数出现了%d次\n", num, i);
}
