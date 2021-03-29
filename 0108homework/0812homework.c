//计算年龄
#include<stdio.h>

int main(void)
{
	int age = 10, num = 1;

	for(num; num < 5; ++num)
		age += 2;

	printf("第%d人年龄为%d\n", num, age);

}
