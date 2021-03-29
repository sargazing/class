#include<stdio.h>

int main()
{
	int n;
	int a[9];

	do
	{
		printf("请输入元素数：");

		scanf("%d", &n);
	}while(n < 1 || n > 9);
	
	int i = 0; 

	char c;

//	while(1)
	for(int i = 0; i < n; i ++)
	{
		scanf("%d", a + i);

	//	c = getchar();

	//	if(c == '\n');

	//	break;

	//	i ++;
	}

	for(int j = 0; j < n; j++)
//		printf("%5d", a[j]);
		printf("%d\n", a[j]);

//	printf("%d\n", a[1]);
}
