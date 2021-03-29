#define _XOPEN_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<shadow.h>
#include<string.h>

int main(int argc, char **argv)
{
	char *arr = getpass("密码：");

	struct spwd *oldpass = getspnam(argv[1]);

	char *newpass;

	arr = crypt(arr, oldpass->sp_pwdp);

	if(strcmp(arr, oldpass->sp_pwdp))
		printf("错误\n");
	else
		printf("OK\n");

	return 0;
}
