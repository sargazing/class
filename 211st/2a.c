#include<stdio.h>

int main()
{
	int sum = 0, num;

	printf("请输入所求项数：");

	scanf("%d", &num);

	for(num; num > 0; num--)
		sum += num;

	printf("%d\n", sum);
}
