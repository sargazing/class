#include<stdio.h>

int size();
int main()
{
	char str[] ={ "aaaaaaaaa"};

	printf("%d\n", size(str));
}

int size(char *str)
{
	int n = 0;
	
	for(int i = 0; *(str + i) != '\0'; i++)
		n += sizeof (str + i);
	return n;
}
