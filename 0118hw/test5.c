#include<stdio.h>

int main()
{	int i,j;
	
	char oper;
	
	printf("请输入四则运算式:");

	scanf("%d%c%d", &i, &oper, &j);

	if(oper == '/' || j == 0)
	{
		printf("error\n");

		return 1;
	}

	switch(oper)
	{
		case '+':printf("%d + %d = %d\n", i, j, i + j);break;
	
		case '-':printf("%d - %d = %d\n", i, j, i - j);break;
	
		case '*':printf("%d * %d = %d\n", i, j, i * j);break;
	
		case '/':printf("%d / %d = %d\n", i, j, i / j);break;
	}
}
