#ifndef SOCKET_WRP_H
#define SOCKET_WRP_H

typedef struct _socketwrp_t_
{
	int socketfd;
}socketwrp_t;

socketwrp_t * socketwrp_connect(unsigned long host, int port);
socketwrp_t * socketwrp_create();
int           socketwrp_bind(socketwrp_t * skt, unsigned long host, int port);
void          socketwrp_close(socketwrp_t * skt);
int           socketwrp_sendto(socketwrp_t * skt, unsigned long host, int port,
					const char * buf, int len);
int           socketwrp_recvfrom(socketwrp_t * skt, unsigned long * host, 
					int * port, char * buf, int len);

#endif
