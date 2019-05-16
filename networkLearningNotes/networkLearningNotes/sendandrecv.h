#pragma once
//this two functions are for communicatiing over stream sockets
//int send(int sockfd, const void *msg, int len, int flags);
//flags = 0
/*
void sendSample()
{
	char* msg = "Beej was here";
	int len, bytes_sent;
	//...
	len = strlen(msg);
	bytes_sent = send(sockfd, msg, len, 0);
}
*/

//int recv(int sockfd, void *buf, int len, int flags);
//flags = 0
//recv() return 0 means the remote side has closed the connection on you.