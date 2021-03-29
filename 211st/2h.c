//4
#include<stdio.h>

#define N 5

int main()
{
	int a[N];
	int b[N];

	printf("请输入5个整形数：");

	for(int i = 0; i < N; i++)
	{
		scanf("%d", a + i);
	}
	printf("b = {");
	
	for(int j = 0; j < N; j++)
	{
		b[j] = a[N - 1 - j];

		printf("%3d", b[j]);
	}
	printf("}\n");

	return 0;
}
