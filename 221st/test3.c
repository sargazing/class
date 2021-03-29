#include<stdio.h>

char *mycopy();
char stcat(char *m, char *n);
int longsize();

int main()
{
	char a[20] = "hello word";
	char b[20] = "";

	*mycopy(b, a);
	stcat(a, b);

	for(int j = 0; a[j] != '\0'; j++)
		putchar(a[j]);
	printf("\n");

	for(int j = 0 ; b[j] != '\0'; j++)
		putchar(b[j]);
	printf("\n");

//	int i, j;

//	for(i = 0; a[i] != 0; i++);
//	for(j = 0; b[j] != 0; j++);

//	result = i - j;
	if(longsize(b,a))
		printf("a元素多%d个\n", longsize(a, b));
	else
		printf("b元素多%d个\n", -longsize(a, b));
	
	return 0;
}

char *mycopy(char *b, char*a)
{
	int i;

	for( i = 0; a[i] != '\0'; i++)
		b[i] = a[i];
	
	b[i] = '\0';

	printf("\n");
	
	return b; 
}
char stcat(char *m, char*n)
{	
	int i;
	for(i = 0; m[i] != 0; i++);
	
	mycopy(m + i; n);
//	for(j = 0; n[j] != 0; j++)
//		m[i + j] = n[j];
	
//	m[i + j] = '\0';
	return *m;
}
int longsize(char *a, char *b)
{
	int i, j;

	while(a[i] == b[i] && a[i] == '\0')
	{
	 return a[i] - b[i];
	}
}
