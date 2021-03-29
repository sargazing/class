#include<stdio.h>

//输出第i项斐波那契数列
int fbnq(int i)
{

	if(i == 1 || i == 2)
		return 1;
	else
	{
		i = fbnq(i - 1) + fbnq(i - 2);

		return i;
	}
}

int main(void)
{
	int in, a;
	
	printf("请输入求斐波那奇数列第几项：");

	scanf("%d", &in);

	in = fbnq(in);

	printf("%d\n", in);
}
