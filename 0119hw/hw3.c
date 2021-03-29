#include<stdio.h>

#define NUM		10
#define NUM2	19
#define BAD(i)			i =(int)NUM * (int)NUM2

int main()
{
	int i = 4, j = 56;
	printf("%d", NUM);
//	BAD(i, j);
	printf("%d", BAD(j));

}
