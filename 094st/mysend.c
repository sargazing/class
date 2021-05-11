#include<unistd.h>
#include<stdio.h>
#include <arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/udp.h>
#include"proto.h"


int main(int argc, char *argv[])
{
	int sfd;
	struct sockaddr_in addr, raddr;
	socklen_t len;
	char buf[MSGMAX];

	sfd = socket(AF_INET, SOCK_DGRAM, 0);

	if(sfd == -1)
	{
		perror("socket()");
		exit(1);
	}
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(RCVPORT);
	inet_aton(RCVIP, &addr.sin_addr);
	len = sizeof(addr);
/*
	if(bind(sfd, (struct sockaddr *)&addr, len) == -1);
	{
		perror("bind()");
		goto ERROR;
	}
*/	
	//memset(buf, '\0', MSGMAX);
	//		recvfrom(sfd, buf, MSGMAX, 0, (struct sockaddr *)&raddr, &len);
	sendto(sfd, argv[1], sizeof(argv[1]), 0, (struct sockaddr *)&addr, len);

	close(sfd);
	exit(0);

ERROR:
	close(sfd);
	exit(1);
}
