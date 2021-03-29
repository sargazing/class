#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

static int sumFileblock(char *path);
static int isDir(struct stat buf);
static char *pathCat(char *path, char *name);
int main(int argc, char *argv[])
{
	if(argc < 2)
		return 1;

	DIR *dp = opendir(argv[1]);
	int size = 0;
	struct stat buf;
	char *dirname;
	char *filename;
	struct dirent *str;

	size = sumFileblock(argv[1]) / 2;

	printf("%dk\n", size);

	closedir(dp);

	return 0;

READERR:

	closedir(dp);
	return 1;
}
static int sumFileblock(char *path)
{
	int blocks = 0;
	DIR *dp = opendir(path);

	if(dp == NULL)
	{
		perror("opendir");

		return -1;
	}

	struct stat buf;
	char *file_path;
	struct dirent *str;
	char flag1[2] = ".";
	char flag2[3] = "..";
	int key;

	if(stat(path, &buf) == EOF)
	{
		perror("stat()");
		return -1;
	}
	blocks += buf.st_blocks;

	while(1)
	{
		str = readdir(dp);
		if(str == NULL)
		{
			if(errno == 0)
				return blocks;

			perror("readdir()");
			return -1;
		}

		if(!(strcmp(flag1, str->d_name) && strcmp(flag2, str->d_name)))
			continue;

		file_path = pathCat(path, str->d_name);

		if(lstat(file_path, &buf) == EOF)
		{
			perror("stat()");
			return -1;
		}
		if(isDir(buf))
		{
			key = sumFileblock(file_path);

			if(key == -1)
			{
				printf("error\n");

				return -1;
			}

			blocks += key;

			continue;
		}

		blocks += buf.st_blocks;

	}

	free(file_path);

}
static char *pathCat(char *path, char *name)
{
	char *dirname;

	dirname = realloc(dirname, strlen(path) + 2 + strlen(name));

	memset(dirname , '\0', sizeof(dirname));

	memcpy(dirname, path, strlen(path) + 1);

	dirname = strcat(dirname, "/");

	dirname = strcat(dirname, name);
}

static int isDir(struct stat buf)
{
	if(buf.st_mode & S_IFDIR)
		return 1;
	return 0;
}

