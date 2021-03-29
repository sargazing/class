#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<errno.h>

int main(int argc, char *argv[])
{
	DIR *dp = opendir(argv[1]);

	if(dp == NULL)
	{
		perror("opendir()");
		return 1;
	}

	struct dirent *str;

	while(1)
	{
		str = readdir(dp);

		if(str == NULL)
		{
			if(errno == 0)
				break;
		
			perror("readdir()");
			
			goto READERR;
		}
	
		printf("%s\n", str->d_name);
	}

	closedir(dp);

	return 0;

READERR:

	closedir(dp);
	return 1;
}
