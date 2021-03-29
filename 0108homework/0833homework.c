//百钱百鸡求解

#include<stdio.h>

int main(void)
{
	for(int rooster = 1; rooster < 100; rooster++)	
	{
		for(int cub = 0; cub <= 100 - rooster; cub += 3)
		{
			if (cub / 3 + rooster * 3 + (100 - rooster - cub) * 2 == 100)
				printf("公鸡%d只，母鸡%d只，雏鸡%d只\n", rooster, 100 - rooster - cub, cub);
		}
	}
}	
