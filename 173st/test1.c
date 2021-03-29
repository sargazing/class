#include<stdio.h>
#include<string.h>

#define ERROPEN perror("fopen()"); return -1;
#define FERR(aaa) if(aaa == NULL) return -1;
#define SIZE 10

int ins_flie(char **v);
int line_rd(FILE *fpa, FILE *fpb);
int main(int argc , char **argv)
{
	if(argc < 4)
	{
		printf("argc < 4\n");
		return 1;
	}
	ins_flie(argv);	

	return 0;
}

int ins_flie(char **v)
{
	FILE *fpa = fopen(v[1], "r");
	
	if(fpa == NULL)
		ERROPEN;
	
	FILE *fpb = fopen(v[3], "w+");
	
	if(fpb == NULL)
		ERROPEN;
	
	for(int i = 0; i < (int)v[2][1] - 1 ; i++)
		if(line_rd(fpa, fpb) == -1)
			return -1;

	if(fputs(v[3], fpb) == EOF)
		if(ferror(fpb))
		{
			printf("put v[3] error\n");
			return -1;
		}
	while(line_rd(fpa, fpb) != 0);


}
int line_rd(FILE *fpa, FILE *fpb)
{
	char arr[SIZE];
	int c;
	
	while(c != 10 && c != EOF)
	{
		c = getc(fpa);
		if(putc(c, fpb) == EOF)
		{
			if(ferror(fpb))
			{
				printf("put error\n");
				return -1;
			}
		}
	}
	if(ferror(fpa))
	{
		printf("get error\n");
		return -1;
	}
	if(feof(fpa))
		return 0;
	return 1;
}
