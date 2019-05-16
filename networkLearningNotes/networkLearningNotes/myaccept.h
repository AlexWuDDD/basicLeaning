#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include "getaddrinfo.h"

/*
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
*/

#define MYPORT "3490"
#define BACKLOG 10

int testAccept()
{
	struct sockaddr_storage their_addr;
	socklen_t addr_size;
	struct addrinfo hints, * res;
	int sockfd, new_fd;

	//!!don't forget your error checking for these calls !!

	//first, load up address structs with getaddrinfo()
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(NULL, MYPORT, &hints, &res);

	//make a socket, bind itm and listen to it
	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	bind(sockfd, res->ai_addr, res->ai_addrlen);
	listen(sockfd, BACKLOG);

	//now accept an incoming connection
	addr_size = sizeof(their_addr);
	new_fd = accept(sockfd, (struct sockaddr*) & their_addr, &addr_size);
	
	//read to communicate on socket descriptor new_fd!
	//...
}