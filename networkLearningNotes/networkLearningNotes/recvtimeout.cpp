#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <errno.h>

int recvtimeout(int s, char* buf, int len, int timeout)
{
	fd_set fds;
	int n;
	struct timeval tv;

	//set up the file descriptor set
	FD_ZERO(&fds);
	FD_SET(s, &fds);

	//set up the struct timeval for the timeout
	tv.tv_sec = timeout;
	tv.tv_usec = 0;

	//wait until timeout or data received

	n = select(s + 1, &fds, NULL, NULL, &tv);
	if (n == 0) return -2; //timeout!
	if (n == -1) return -1; //error

	//data must be here, so do a normal recv()
	return recv(s, buf, len, 0);
}

int main()
{
	int sockfd = 0;
	char buf[255] = { 0 };
	int n = recvtimeout(sockfd, buf, sizeof(buf), 10);// 10 second timeout

	if (n == -1) {
		//error occurred
		perror("recvtimeout");
	}
	else if (n == -2) {
		//timeout occurred
	}
	else {
		// got some data in buf
	}
}