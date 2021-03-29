#include<stdio.h>
#include<string.h>

int *mystrchr(char c, char *str, int *res);

int main()
{
	char str[] = "abcda";
	int res[(int)strlen(str) + 2];
	
	for(int j = 0; j < strlen(str) + 2; j++)
		res[j] = -1;

	printf("请输入需要查找的字符：");
	
	char c = getchar();

	if(*(mystrchr(c, str, res) + 0) == 1)
		printf("无此字符\n");
	else
	{
		for(int j = 1; *(mystrchr(c, str, res)+ j) >= 0; j++)
			printf("第%d项\n", *(mystrchr(c, str, res)+ j));
	}
}

int *mystrchr(char c, char *str, int *res)
{
	int count = 1;
	int i;

	for(i = 0; i <= strlen(str) + 1; i++)
	{
		if(str[i] == c)
			res[count++] = i;
	}
	if(count == 1)
		res[0] = 1;

	return res;
}

