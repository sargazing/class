#include<glob.h>
#include<stdio.h>
#include<string.h>

int main(int argc , char **argv)
{
	glob_t res;

//	char arr[128] = "/*"; 

	glob(argv[1], 0, NULL, &res);
	//glob("/etc/*", GLOB_APPEND, NULL, &res);
//	puts(arr);
	for(int i = 0; i < res.gl_pathc; i++)
	{
		puts((res.gl_pathv)[i]);
	}
	return 0;
}
