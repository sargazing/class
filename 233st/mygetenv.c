#include<stdio.h>
#include<stdlib.h>

extern char **environ;

int main()
{
	char *p = getenv("LD_LIBRARY_PATH");
	puts(p);
	int k = setenv("PATH", "~/work", 1);
	p = getenv("PATH");

	puts(p);

//	for(int i = 0; environ[i]; i++)
//		puts(environ[i]);
	return 0;
}
