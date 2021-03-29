#include<stdio.h>
#include<string.h>

int *mystrstr(char *str_s, char *str, int *res);

int main()
{
	char str[] = "abcd abcd";
	char str_s[(int)strlen(str) + 1];
	int res[(int)strlen(str) + 2];
	int i = 0;

	for(int k = 0; k < (int)strlen(str) + 2; k++)
		res[k] = -1;

	printf("请输入需要查找的字符串：");
	while(1)
	{
		char c = getchar();

		if(c == '\n' || i == (int)strlen(str))
		{
			str_s[i] = '\0';
			break;
		}
		str_s[i] = c;

		i++;
	}
	
	if(*(mystrstr(str_s, str, res)) == 1)
		printf("无此字符\n");
	else
	{
		for(int j = 1; *(mystrstr(str_s, str, res)+ j) >= 0; j++)
			printf("该字符串始出现于第%d项\n", *(mystrstr(str_s, str, res)+ j));
	}
}

int *mystrstr(char *str_s, char *str, int *res)
{
	int count = 1;
	int i, j, k;
	int D_value = strlen(str) - strlen(str_s);

	for(i = 0; i <= D_value; i++)
	{
		k = 1;
		for(j = 0; j < strlen(str_s); j++)
		{
			if(str_s[j] != str[j + i])
			{	
				k = 0;
				break;
			}
		}
		if(k)
		{
			res[count] = i;
			count++;
		}
		else
			continue;
	}
	if(count == 1)
		res[0] = 1;

	return res;
}

