/* 输出：
      *
	* * *
  * * * * *
    * * *
      *
 */	 
#include<stdio.h>

int main()
{
	int num, num2;

	printf("请输入行数：");

	scanf("%d", &num);

	for(int j = 1; j < 2 * num; j++)
	{
		int  i = num - j;

		if(i < 0)
			i = -i;
		for(int j = 1; j <= i; j++)
			printf("  ");
		for(int j = 1; j <=2 * num -2 * i - 1; j++)
			printf(" *");
		printf("\n");
	}	
}
