#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <arpa/inet.h>
#include <netinet/in.h>

/*
int getaddrinfo(const char *node,	//e.g. "www.example.com" or IP
				const char *service, //e.g. "http" or port number
				const struct addrinfo *hints,
				struct addrinfo **res)
*/


int test_getaddrinfo()
{
	int status;
	struct addrinfo hints;
	struct addrinfo* servinfo; // will point to the results

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE; //assign the address of my local host to the socket structure

	if ((status == getaddrinfo(NULL, "3490", &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
		exit(1);
	}

	// servinfo now points to a linked list of 1 or more struct addinfos

	// ... do everything until you don't need servinfo anymore ....

	freeaddrinfo(servinfo);
	
	return 0;
}

/*
showip --- show ip address for a host given on the command line
*/

int showip(int argc, char * argv[])
{
	struct addrinfo hints, * res, * p;
	int status;
	char ipstr[INET6_ADDRSTRLEN];

	if (argc != 2) {
		fprintf(stderr, "usage: showip hostname\n");
		return 1;
	}

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
		return 2;
	}

	printf("IP address for %s: \n\n", argv[1]);
	for (p = res; p != NULL; p = p->ai_next) {
		void* addr;
		char* ipver;

		//get the pointer to the address itself
		//different fields in IPv4 and IPv6
		if (p->ai_family == AF_INET) {
			struct sockaddr_in* ipv4 = (struct sockaddr_in*)p->ai_addr;
			addr = &(ipv4->sin_addr);
			ipver = "IPv4";
		}
		else {
			struct sockaddr_in6* ipv6 = (struct sockaddr_in6*)p->ai_addr;
			addr = &(ipv6->sin6_addr);
			ipver = "IPv6";
		}
		//convert the IP to a string and print it;
		inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
		printf(" %s: %s\n", ipver, ipstr);
	}

	freeaddrinfo(res);
	return 0;
}