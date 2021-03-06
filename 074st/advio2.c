#include<sys/epoll.h>
#include<sys/select.h>
#include<sys/time.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>

#define BUFSIZE 32

enum{RDSTA, WRSTA, ERRSTA, END};

struct relay_st
{
	int state;
	int cnt;
	char *err;
	char buf[BUFSIZE];
	int rfd;
	int wfd;
	int seek;
};
void _rd_drive(struct relay_st *str)
{
	str->cnt = read(str->rfd, str->buf, BUFSIZE);
	
	if(str->cnt == 0)
	{
		str->state = END;
		return;
	}
	else if(str->cnt == -1 && errno != EAGAIN)
	{
		str->err = "read() error ";
		str->state = ERRSTA;
	}
	else if(str->cnt == -1)
		return;
	else
		str->state = WRSTA;
}
void _wr_drive(struct relay_st *str)
{
	int n;

	n = write(str->wfd, str->buf + str->seek, str->cnt);

	if(n == -1 && n != EAGAIN)
	{
		str->err = "write() error";
		str->state = ERRSTA;
		return;
	}
	else if(n < str->cnt)
	{
		str -> seek += n;
		str->cnt -= n;
	}
	else
	str->state = RDSTA;
}
void _err_drive(struct relay_st *str)
{
	puts(str->err);

	str->state = END;
}

int realy_drive(struct relay_st *str)
{
	switch(str->state)
	{
		case END:    return 0       ; break;
		case RDSTA:  _rd_drive(str) ; break;
		case WRSTA:  _wr_drive(str) ; break;
		case ERRSTA: _err_drive(str); break;
	}
}
static struct relay_st *relay_init(int rfd, int wfd)
{
	int rfd_save, wfd_save;
	struct relay_st *str = malloc(sizeof(*str));
	if(str == NULL)
		return NULL;
	rfd_save = fcntl(rfd, F_GETFL);
	fcntl(rfd, F_SETFL, rfd_save | O_NONBLOCK);
	wfd_save = fcntl(wfd, F_GETFL);
	fcntl(wfd, F_SETFL, wfd_save | O_NONBLOCK);

	str->rfd = rfd;
	str->wfd = wfd;
	str->seek = 0;
	str->state = RDSTA;
	str->err = NULL;
	str->cnt = 0;
	memset(str->buf, '\0', BUFSIZE);

	return str;
}

int main(int argc, char *argv[])
{
	if(argc < 3)
		return 1;
	
//	fd_set rset, wset;	
	int epfd;
	struct relay_st *str, *str2;
	int fd11, fd10;
	struct epoll_event even[2], reven;

	fd11 = open(argv[1], O_RDWR | O_NONBLOCK | O_TRUNC);
	if(fd11 == EOF)
	{
		perror("open()");
		return 1;
	}
	
	fd10 = open(argv[2], O_RDWR | O_NONBLOCK | O_TRUNC);
	if(fd10 == EOF)
	{
		close(fd10);
		perror("open()");
		return 1;
	}

	epfd = epoll_create(1);

	even[0].events = 0;
	even[1].events = 0;
	even[0].data.fd = fd10;
	even[1].data.fd = fd11;

	epoll_ctl(epfd, EPOLL_CTL_ADD, fd10, even);
	epoll_ctl(epfd, EPOLL_CTL_ADD, fd11, even + 1);

	str = relay_init(fd10, fd11);
	str2 = relay_init(fd11, fd10);

	while(1)
	{

		if(str->state == END && str2->state == END)
			break;
		if(str->state == ERRSTA)
		{
			realy_drive(str);
			continue;
		}
		if(str2->state == ERRSTA)
		{
			realy_drive(str2);
			continue;
		}
//		FD_ZERO(&rset);
//		FD_ZERO(&wset);

		even[0].events = 0;
		even[1].events = 0;
		even[0].data.fd = fd10;
		even[1].data.fd = fd11;
		if(str->state == RDSTA)
			even[0].events |= EPOLLIN;
		else
			even[1].events |= EPOLLOUT;
		if(str2->state == RDSTA)
			even[1].events |= EPOLLIN;
		else
			even[0].events |= EPOLLOUT;

		epoll_ctl(epfd, EPOLL_CTL_MOD, fd10, even);
		epoll_ctl(epfd, EPOLL_CTL_MOD, fd11, even + 1);
	
		while(epoll_wait(epfd, &reven, 1, -1) == -1)
		{
			if(errno == EINTR)
				continue;
			else
			{
				perror("select()");
				goto ERROR;
			}
		}
		if(reven.data.fd == fd10 && reven.events & EPOLLIN \
			|| reven.data.fd == fd11 && reven.events & EPOLLOUT)
			realy_drive(str);

		if(reven.data.fd == fd11 && reven.events & EPOLLIN \
			|| reven.data.fd == fd10 && reven.events & EPOLLOUT)
			realy_drive(str2);
	}
	close(fd10);
	close(fd11);
	free(str);
	free(str2);
	str = NULL;
	str2 = NULL;

	exit(0);

ERROR:
	close(fd10);
	close(fd11);
	free(str);
	free(str2);
	str = NULL;
	str2 = NULL;

	exit(1);
}
