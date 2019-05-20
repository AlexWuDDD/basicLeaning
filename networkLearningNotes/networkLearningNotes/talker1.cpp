/*
 * a datagram "client" demo
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <arpa/inet.h>

#define SERVERPORT "4950"

int main(int argc, char* argv[])
{
	int sockfd;
	struct addrinfo hints, *servinfo, * p;
	int rv;
	int numbytes;

	if (argc != 3) {
		fprintf(stderr, "usage: talker hostname message\n");
		exit(1);
	}

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;

	if ((rv = getaddrinfo(argv[1], SERVERPORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
	}

	//loop through all the results and bind to the first we can
	for (p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
			perror("listner: socket");
			continue;
		}

		break;
	}

	if (p == NULL) {
		fprintf(stderr, "listener: failed to bind socket\n");
		return 2;
	}


	if ((numbytes = sendto(sockfd, argv[2], strlen(argv[2]), 0, p->ai_addr, p->ai_addrlen)) == -1) {
		perror("recvfrom");
		exit(1);
	}

	freeaddrinfo(servinfo);

	printf("talker: send %d bytes to %s\n", numbytes, argv[1]);
	close(sockfd);
	return 0;

}
