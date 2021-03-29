//n+100是完全平方数 n+ 100 + 168是完全平方数 求n

#include<stdio.h>
#include<math.h>

int main()
{
	for(int i = 1; i <= sqrt(2000 + 100); i++)
	{	
		for(int j = i; j <= sqrt(2000 + 100 + 168); j++)
		{
			if(j * j == i * i + 168)
				printf("%d\n", i * i - 100);
		}
	}
}
