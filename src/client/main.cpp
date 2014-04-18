#include <stdio.h>
#include <windows.h>
#include "../common/socketwrp.h"

int main(int argc, char * argv[])
{
	WSADATA wsaData;
	WORD wVersionRequested = MAKEWORD( 2, 2);
	WSAStartup( wVersionRequested, &wsaData );

	socketwrp_t * skt = socketwrp_create();

	unsigned long host = inet_addr("127.0.0.1");
	int len = socketwrp_sendto(skt, host, 1234, "hello world", 12);

	printf("%d\n", len);
	socketwrp_close(skt);
	getchar();
	return 0;
}
