#pragma once
#include <sys/types.h>
#include <sys/socket.h>

int sendall(int s, char* buf, int* len)
{
	int total = 0; // how many bytes we've sent
	int bytesleft = *len; // how many we have left to send
	int n;
	while (total < *len) {
		n = send(s, buf + totalm bytesleft, 0);
		if (n == -1) {
			break;
		}
		total += n;
		bytesleft -= n;
	}

	*len = total; //return number actually we sent here
	return n == -1 ? -1 : 0; //return -1 on failure, 0 on success
}

int CallSample()
{
	char buf[10] = "Beej!";
	int len;
	len = strlen(buf);
	if (sendall(s, buf, *len) == -1) {
		perror("sendall");
		printf("We only send %d bytes because of the error!\n", len);
	}
}