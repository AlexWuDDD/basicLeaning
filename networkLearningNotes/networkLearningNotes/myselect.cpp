/* a select() demo*/

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define STDIN 0

int main(void)
{
	struct timeval tv;
	fd_set readfds;

	tv.tv_sec = 2;
	tv.tv_usec = 500000;

	FD_ZERO(&readfds); // clear all entries from the set
	FD_SET(STDIN, &readfds); //Add fd to the set

	//don't care about writefds and exceptions
	select(STDIN + 1, &readfds, NULL, NULL, &tv);

	if (FD_ISSET(STDIN, &readfds)) { // return true is fd is in the set
		printf("A key was pressed!\n");
	}
	else {
		printf("Timed out.\n");
	}

	return 0;
}
