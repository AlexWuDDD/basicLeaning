#pragma once
#include "getaddrinfo.h"

#include <sys/types.h>
#include <sys/socket.h>

/*
int connect(int sockfd, struct sockaddr &serv_addr, int addelen);
*/

int testConnect()
{
	struct addrinfo hints, *res;
	int sockfd;

	//first, load up address structs with getaddrinfo();

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	getaddrinfo("www.example.com", "3490", &hints, &res);

	//make a socket
	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

	//connect
	connect(sockfd, res->ai_addr, res->ai_addrlen);
}