//数字加密
#include<stdio.h>


int main()
{
	printf("请输入一个数字：");

	int num;

	scanf("%d", &num);
	
	for(int i = 1; i <= 1000; i *= 10)
	{
		num = (num / i % 10 + 9) % 10 * i + num % i + num / i / 10 *  i * 10;
	}

	printf("the  encrypted number is %d\n", num);
	int unit = num % 10;
	int hundreds = num / 100 % 10;
	int deca = num / 10 % 10;
	int kb = num / 1000;

	int v = kb * 10 + hundreds  + deca * 1000 + unit * 100; 

	printf("the  encrypted number is %d\n", v);

	return 0;
}
