#include<stdio.h>

//char *aaa()
//{
//	char a[] = "hello";
//	return a;
//}
char *bbb()
{
	char *b = "aaa";
	return b;
}

int main()
{
	char * c;
//	puts(c);
	c =bbb();
	puts(c);
	return 0;
}
