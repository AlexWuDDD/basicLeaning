#pragma once
#include "getaddrinfo.h"

#include <sys/types.h>
#include <sys/socket.h>
/*
int bind(int socketfd, struct socket* my_addr, int addrlen);
*/

#define MYPORT 3490

int testbind()
{
	struct addrinfo hints, * res;
	int sockfd;

	//first, load up address structs with getaddrinfo()
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(NULL, "3490", &hints, &res);

	//make a socket;
	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	//bind it to the port we passed in to getaddrinfo();

	bind(sockfd, res->ai_addr, res->ai_addrlen);
	return 0;
}

int oldways()
{
	int sockfd = socket(PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in my_addr;
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(MYPORT);
	my_addr.sin_addr.s_addr = inet_addr("10.12.110.57");
	memset(my_addr.sin_zero, '\0', sizeof(my_addr.sin_zero));

	bind(sockfd, (struct sockaddr*) & my_addr, sizeof(my_addr));

	return 0;
}

int reusePort()
{
	int yes = 1;
	int listner;
	//lost the pesky "Address already in use" error message
	if (setsockopt(listner, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes) == -1)) {
		perror("setsocketopt");
		exit(1);
	}
}