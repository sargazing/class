#include<stdio.h>
#include<unistd.h>

int main(int argc, char **argv)
{
	if(argc < 3)
		return 1;

	FILE *fp;
	char data[15];
	int cnt;

	fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		perror("fopen()");
		return 1;
	}

	FILE *wfp = fopen(argv[2], "w");

	while(1)
	{
/*	//	data = getc(fp);
		if(fgets(data, 15, fp) == NULL)
		{
			if(feof(fp))
				break;
			else
				goto ERR;
		}
		fputs(data,  stdout);
		sleep(1);*/
		cnt = fread(data, 1, 15, fp);
		if(cnt == 0)
		{
			if(feof(fp))
				break;
			return 1;
		}
		fwrite(data, 1, cnt, stderr);
	}

	fclose(fp);
	return 0;
ERR1:
	fclose(fp);
ERR:
	return 1;
}
