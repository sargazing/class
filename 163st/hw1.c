#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#define SIZE 1024

int cnt_word(int fd1, int cnt);
int ins_flie(int fd1, int fd2, char *str, int len);
int main(int argc, char **argv)
{
	if(argc < 3)
		return 1;

	int fd1 = open(argv[1], O_RDONLY); 
	if(fd1 == -1)
	{
		perror("open()");
		goto ERR1;
	}
	
	int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if(fd2 == -1)
	{
		perror("open()");
		goto ERR2;
	}
	int len = lseek(fd1, 0, SEEK_END);

	printf("%d\n", cnt_word(fd1, len));

	ins_flie(fd1, fd2, "HELLO EVERY ONE", len);

	close(fd1);
	close(fd2);
	return 0;

ERR2:
	close(fd1);
ERR1:
	return 1;
}
int cnt_word(int fd1, int cnt)
{
	int count = 0;
	char data;
	int key;
	while(cnt-- > 0)
	{
		key = lseek(fd1, cnt, SEEK_SET);
		if(key == -1)
		{
			perror("lseek()");
			return -1;
		}
		
		read(fd1, &data, 1);
		if(key == -1)
		{
			perror("read()");
			return -1;
		}

		if(data == '\n' || data == ' ')
			count++;
	}
	return count;
}
int ins_flie(int fd1, int fd2, char *str, int len)
{
	int cnt = 0;
	int i;
	char data;
	int key;
	char arr[SIZE];
	
	key = lseek(fd1 , 0, SEEK_SET);

	if(key != 0)
	{
		perror("lseek()");
		return -1;
	}

	for(i = 0; i < len; i++)
	{
		key = read(fd1, &data, 1);
		if(key == -1)
		{
			perror("read()");
			return -1;
		}
		key = write(fd2, &data, 1);
		if(key == -1)
		{
			perror("write()");
			return -1;
		}
		if(data == '\n')
			cnt++;
		if(cnt == 3)
			break;
	}

	key = write(fd2, str, strlen(str));
	if(key == -1)
	{
		perror("write()");
		return -1;
	}
	while(1)
	{
		key = read(fd1, arr, SIZE);
		if(key == -1)
		{
			perror("read()");
			return -1;
		}
		if(key == 0)
			break;
		key = write(fd2, arr, key);
		if(key == -1)
		{
			perror("write()");
			return -1;
		}
	}
}
