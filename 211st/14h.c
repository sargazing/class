//14
#include<stdio.h>

#define N 10

int main()
{
	int arr[N];

	printf("请输入10个整形数：");

	for(int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);	
	}

	int  pos, zero;

	pos = zero = 0;

	for(int j = 0; j < N; j++)
	{
		if(arr[j] == 0)
			zero++;
		else if(arr[j] > 0)
			pos++;
	}
	printf("正数有%d个；负数有%d个；0有%d个\n", pos, zero, N - zero - pos);

	return 0;
}
