#include<stdio.h>

int aa(int *i)
{
	*i = 6;
	return 0;
}
int main ()
{
	int c = 5;
	aa(&c);
	printf("%d\n", c);
}
