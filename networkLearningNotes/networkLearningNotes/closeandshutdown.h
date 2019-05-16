#pragma once
//void close(sockfd);
//int shutdown(int sockfd, int how);
// how::
//0: Further receives are disallowed
//1: Further sends are disallowed
//2: Further sends and recives are disallowed(like close())
// ----------------- !!! Note !!! --------------------------------
// shutdown doesn't actually close the file descriptor 
// it just changes its usability.
// to free a socket descriptor, you need to use close()
