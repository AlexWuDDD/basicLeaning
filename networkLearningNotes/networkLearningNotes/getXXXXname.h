#pragma once
//getpeername() will tell you who is at the other end of a connected socket
#include <sys/socket.h>

//int getpeername(int sockfd, struct sockaddr *addr, int addrlen);

#include <unistd.h>

//int gethostname(char *hostname, size_t size);