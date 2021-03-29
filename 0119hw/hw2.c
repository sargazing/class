//求最大公约数
#include<stdio.h>

int  num_s();

int main()
{
	int num1, num2;

	printf("请输入两个整型数(i,j)：");

	scanf("%d,%d", &num1, &num2);

	printf("公约数为%d\n", num_s(num1, num2));
}

int num_s(int i, int j)
{
	if(i % j == 0)
		return j;
	else 
		num_s(j, i % j);

}

