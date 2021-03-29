#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<stdlib.h>

#define ELSE else printf("-");
#define SIZE 100

static void myFileType(const struct stat p);
static void myFilePm(const struct stat arr);
static void myFileHardlink(const struct stat p);
static void myFlieUsername(const struct stat p);
static void myFlieGroupname(const struct stat p);
static void myFilesize(const struct stat p);
static void myFiletime(const struct stat p);
int main(int argc, char **argv)
{
	time_t sec;

	time(&sec);

	if(sec == EOF)
	{
		printf("time error\n");
g	
		return 1;		
	}
	struct tm *buf;
	char str[SIZE];

	buf = localtime(&sec);

	if(buf == NULL)
	{
		printf("buf error\n");

		return 1;
	}
	
	printf("daylight = %d\n", buf->tm_isdst);

	buf->tm_mday += atoi(argv[1]);

//	while(buf->tm_day > 30)
	if(buf->tm_mday > 365)
	{
		buf->tm_yday -= 365;
		buf->tm_year+= 1;
		buf->tm_mon -= 12;
	}

	sec = mktime(buf);
	
	buf = localtime(&sec);

	strftime(str, SIZE, "%Y/%m/%d", buf);

	printf("daylight = %d\n", buf->tm_isdst);
	puts(str);
	
	return 0;
}
static void myFileType(const struct stat p)
{
	switch (p.st_mode & S_IFMT) {
		case S_IFBLK:  printf(" b "); break;
		case S_IFCHR:  printf(" c "); break;
		case S_IFDIR:  printf(" d "); break;
		case S_IFIFO:  printf(" f "); break;
		case S_IFLNK:  printf(" s "); break;
		case S_IFREG:  printf(" r "); break;
		case S_IFSOCK: printf(" s "); break;
		default:       printf(" un"); break;

		return;
	}
}

static void myFilePm(const struct stat arr)
{
	if((arr.st_mode & S_IRUSR))
		putchar('r');
	ELSE
	if((arr.st_mode & S_IWUSR))
		putchar('w');
	ELSE
	if((arr.st_mode & S_IXUSR))	
	{
		putchar('x');
		
		if((arr.st_mode & S_ISUID))
			putchar('s');
		ELSE
	}
	ELSE
	if((arr.st_mode & S_IRGRP))
		putchar('r');
	ELSE
	if((arr.st_mode & S_IWGRP))
		putchar('w');
	ELSE
	if((arr.st_mode & S_IXGRP))
	{
		putchar('x');
		
		if(arr.st_mode & S_ISGID)
			putchar('s');
		ELSE
	}
	ELSE	
	if((arr.st_mode & S_IROTH))
		putchar('r');
	ELSE
	if((arr.st_mode & S_IWOTH))
		putchar('w');
	ELSE
	if((arr.st_mode & S_IXOTH))
	{
		putchar('x');
		
		if(arr.st_mode & S_ISVTX)
			putchar('s');
		ELSE
	}
	ELSE
	return;
}

static void myFileHardlink(const struct stat p)
{
	 printf("%ld " , p.st_nlink);
	 return;
}

static void myFlieUsername(const struct stat p)
{
	struct passwd *arr;
	arr = getpwuid(p.st_uid);
	printf("%s ", arr->pw_name);
}
static void myFlieGroupname(const struct stat p)
{
	struct group *arr;
	arr = getgrgid(p.st_gid);
	printf("%s ", arr->gr_name);
	return;
}
static void myFilesize(const struct stat p)
{
	printf("%ld ", p.st_size);
	return ;
}
static void myFiletime(const struct stat p)
{
	struct tm *buf;
	char arr[SIZE];

	buf = localtime(&p.st_mtime);

	strftime(arr, SIZE, "%m %h %M", buf);

	printf("%s\n", arr);
}
