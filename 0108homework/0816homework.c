//	枚举100～200内的完全平方数
#include<stdio.h>

int main(void)
{
	for(int num = 10; num * num <= 200; num++)
		printf("%4d", num * num);
}
