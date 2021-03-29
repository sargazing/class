#include<stdio.h>
#include<errno.h>

int main(int argc, char *argv[])
{
	if(argc < 2)
		return 1;

	FILE *fp = fopen(argv[1], "r");

	if(fp == NULL)
	{
		perror("fopen()");
		return 1;
	}

	int key = fseek(fp, -10, SEEK_END);
	if(key == -1)
	{
		printf("fseek error\n");
		return 1;
	}

	printf("%ld\n", ftell(fp));

	char arr[60];


	key = fread(arr, 1, 15, fp);
//	if(key)

	key = fwrite(arr, 1, key, stdout);

	return 0;

}
