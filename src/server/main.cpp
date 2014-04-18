#include <stdio.h>
#include <windows.h>
#include "../common/socketwrp.h"

int main(int argc, char * argv[])
{
	WSADATA wsaData;
	WORD wVersionRequested = MAKEWORD( 2, 2);
	WSAStartup( wVersionRequested, &wsaData );

	int rt = 0;
	socketwrp_t * skt = socketwrp_create();
	rt = socketwrp_bind(skt, inet_addr("0.0.0.0"), 1234); 
	printf("%d\n", rt);

	while(1)
	{
		unsigned long host;
		int port;
		char buf[1024] = {0};
		socketwrp_recvfrom(skt, &host, &port, buf, 1024);
		printf("%s\n", buf);
	}
	getchar();
	return 0;
}
