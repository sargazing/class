#include<stdio.h>
#include<getopt.h>
#include<time.h>

int main(int argc, char **argv)
{
	if(argc < 2)
		return 1;
	char key;

	printf("size = %ld\n", sizeof(int *));

	struct option test[] = 
	{
		{"APP", optional_argument, NULL, 'A'},
		{"end", no_argument, NULL, 'e'},
		{0,0,0,0}
	
	};

	while(1)
	{
		key = getopt_long(argc, argv, "", test, NULL);
		
		if(key == -1)
		{
			break;
		}
		putchar(key);
	}



	return  0;
}
