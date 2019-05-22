#include <stdio.h>
#include <sys/unistd.h>

int main()
{
	char hostname[128];
	gethostname(hostname, sizeof(hostname));
	printf("My hostname : %s\n", hostname);
	return 0;
}