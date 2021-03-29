//竞赛成绩
#include<stdio.h>

#define N 10

int main()
{
	int a[N], num, id;

	for(int i = 0; i < N; i++)
	{
		scanf("%d", &num);

		char c = getchar();

		a[i] = num;

		if(c == '\n')
			break;
	}
	printf("请输入题数：");

	scanf("%d", &num);

	for(int j = 0; j < num; j++)
	{
		scanf("%d", &id);

		a[id - 1]++;

		char c = getchar();

		if(c == '\n')
			continue;
	}
	for(int i = 0; i < N; i++)
		printf("%3d号", i + 1);

	printf("\n");

	for(int i = 0; i < N; i++)
		printf("%5d", a[i]);

	printf("\n");
}
