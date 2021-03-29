//1
#include<stdio.h>

void swap1(int a , int b);
void swap2(int a , int b);
void prime();

int main()
{
	prime();
	return 0;
}
void swap1(int a , int b)
{
	int c = a;
	a = b;
	b = c;
}
void swap2(int a , int b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b; 
}
void prime()
{
	int j , i;
	for(i = 200; i > 0; i--)
	{
		for(j = i - 1; j > 0; j--)
		{
			if(i % j == 0)
				break;	
		}
		if(j == 1)
			printf("%5d", i);
	}
	printf("\n");
}
