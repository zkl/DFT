#ifndef SOCKET_WRP_H
#define SOCKET_WRP_H

typedef struct _socketwrp_t_
{
}socketwrp_t;

void socketwrp_create();
void socketwrp_free();
void socketwrp_connect();
void socketwrp_disconnect();
void socketwrp_sendto();
void socketwrp_recvfrom();
void socketwrp_listen();
void socketwrp_accept();

#endif
