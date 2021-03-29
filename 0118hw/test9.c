//99乘法表

#include<stdio.h>

int main()
{
//	int i = 1, j = 1;

	for(int i = 1; i < 10; i++)
	{
		for(int k = 1; k < i; k++)
			printf("               ");
		for(int j = i; j < 10; j++)
		{
			printf(" %2d x %2d = %2d  ", i, j, i * j);
			
			if(j == 9)
				printf("\n");
		}
	}
}
