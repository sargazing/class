#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *myaddstr(char *str , char member);
char *mydelstr(char *str, char member);
char *myfindstr(char *str, char member);
int time();

int main()
{
	char *str;

	int n;

	char find, add, del;

	printf("请输入需要添加的字符：");

	scanf("%c", &add);

	while(getchar() != '\n')
	{}

	time();

	printf("请输入需要删除的字符：");

	scanf("%c", &del);

	while(getchar() != '\n')
	{}
	time();

	printf("请输入需要查找的字符：");

	scanf("%c", &find);

	while(getchar() != '\n')
	{}

	time();

	printf("请输入动态数组元素个数：");
	
	scanf("%d", &n);
	
	str = calloc(n + 1, 1);

	if(str == NULL)
		return -1;
	for(char i = 'A'; i - 'A' < (char)n; i++)
		str[i - 'A'] = i;

	puts(str);

	char *str_add_A = myaddstr(str, add);
	puts(str_add_A);
	
	char *str_del_B = mydelstr(str, del);
	puts(str_del_B);

	char *resG = myfindstr(str, find);

	if(resG[0] == n + 1)
		printf("未找到%c\n", find);

	else
	{	
		for(int k = 0; resG[k] <= strlen(str); k++)
			printf("%c在第%d项\n", find, resG[k] + 1);
	}

	return 0;
}

char *myaddstr(char *str , char member)
{
	size_t size = strlen(str);
	char *str2 = calloc(size + 2, 1);
	
	if(str2 == NULL)
		return NULL;
		
	strcpy(str2, str);

	str2[(int)size] = member;
	
	return str2;
}

char *mydelstr(char *str, char member)
{
	char *str2 = calloc(strlen(str) + 1, 1);
	int i, j = 0;

	if(str2 == NULL)
		return NULL;
	
	for(i = 0; i < strlen(str); i++)
	{
		if(str[i] == member)
			continue;
		
		str2[j]	= str[i];
		
		j++;
	}
	if(j != i)
	{
		char *str3 = realloc(str2, j + 1);

		return str3;
	}
	return str2;
}

char *myfindstr(char *str, char member)
{
	char *arr = malloc(strlen(str) + 1);
	char i, j = 0;

	if(arr == NULL)
		return NULL;
	
	memset(arr, strlen(str) + 1, strlen(str));
	
	for(i = 0; i <= strlen(str); i++)
	{
		if(str[i] == member)
		{
			arr[j] = i;

			j++;
		}
	}
	if(j != i)
	{
		char *arr2 = realloc(arr, j + 1);

		return arr2;
	}

	return arr;
}
int time()
{
	for(int i = 0; i < 530; i++)
		for(int j = 0; j < 200; j++);
}
