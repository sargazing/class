//回数猜想
#include<stdio.h>

int panlin_num();
int ispanlin_num();

int main()
{	
	int num, j = 1, i = 1;

	printf("请输入一个整形数：");

	scanf("%d", &num);

	for(i = 1; i < 8; i++)
	{
		num += panlin_num(num);
		
		if(ispanlin_num(num))
		{
			printf("经过%d次计算，得到回文数%d\n", i, num);
		
			j = 0;

			break;
		}
		//else
		//	num += panlin_num(num);
	}
	if(j)
		printf("经过7次计算，没有得到回文数\n");

}

int panlin_num(int num)
{
	int num_s = 0;

	for(num; num > 0; num /= 10)
	{
		num_s = num_s * 10 + num % 10;
	}

	return num_s;
}
int ispanlin_num(int num)
{
//	num = num + panlin_num(num);

//	if(num == panlin_num(num))
		return num == panlin_num(num);

	return 0;
}
