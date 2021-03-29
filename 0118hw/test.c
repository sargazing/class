#include<stdio.h>
//排序
int main()
{
	int a, b, c;

	printf("输入a, b, c:");

	scanf("%d, %d, %d", &a, &b, &c);

	if(a < b)
	{
		a = a ^ b;

		b = b ^ a;
		
		a = a ^ b;
	}
	if(a < c)
	{
		a = a ^ c;

		c = c ^ a;

		a = a ^ c;
	}
	if(b < c)
	{
		b = c ^ b;
		
		c = b ^ c;

		b = c ^ b;
	}
	printf("a = %d, b = %d, c = %d\n", a, b, c);
}
