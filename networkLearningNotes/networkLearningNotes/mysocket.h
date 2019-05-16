#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include "getaddrinfo.h"

/*
int socket(int domain, int type, int protocol);

domain -- PF_INET, PF_INET6
type -- SOCK_STREAM, SOCK_DGRAM
protocol -- 0
*/

int testSocket()
{
	int s;
	struct addrinfo hints, * res;

	//do the lookup
	//[pretend we already filled out the hints structure]
	getaddrinfo("www.example.com", "http", &hints, &res);

	//[again, you should do error checking on getaddrinfo(), and walk
	//the "res" linked list looking for valid entries instead od just assuming the first one os good
	//See the section on Client/server for real example.]

	s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

	return 0;
}