#include <WINDOWS.H>
#include <malloc.h>
#include "socketwrp.h"

socketwrp_t * socketwrp_connect(unsigned long host, int port)
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = host;  
	addr.sin_port = htons(port);

	int fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(fd == INVALID_SOCKET)
		return 0;

	/* connect error */
	if(connect(fd, (struct sockaddr *)&addr, sizeof(addr)))
		return 0;

	socketwrp_t * skt = (socketwrp_t *)malloc(sizeof(socketwrp_t));
	skt->socketfd = fd;
	return skt;
}

socketwrp_t * socketwrp_create()
{
	int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if(fd == INVALID_SOCKET)
		return 0;

	socketwrp_t * skt = (socketwrp_t *)malloc(sizeof(socketwrp_t));
	skt->socketfd = fd;
	return skt;
}

int socketwrp_bind(socketwrp_t * skt, unsigned long host, int port)
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = host;  
	addr.sin_port = htons(port);
	return bind (skt->socketfd, (struct sockaddr *)&addr, sizeof(addr));
}

void socketwrp_close(socketwrp_t * skt)
{
	if(skt == 0)
		return ;

	closesocket(skt->socketfd);
	free(skt);
}


int socketwrp_sendto(socketwrp_t * skt, unsigned long host, 
					int port, const char * buf, int len)
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = host;  
	addr.sin_port = htons(port);

	return sendto(skt->socketfd, buf, len, 0, (struct sockaddr *)&addr, 
			sizeof(addr));
}

int socketwrp_recvfrom(socketwrp_t * skt, unsigned long * host, int * port, 
		char * buf, int len)
{
	struct sockaddr_in addr;
	int size = sizeof(addr);
	int rt = recvfrom(skt->socketfd, buf, len, 0, (struct sockaddr *)&addr,
			&size); 

	if(host)
		*host = addr.sin_addr.S_un.S_addr;

	if(port)
		*port = htons(addr.sin_port);
	
	return rt;
}

