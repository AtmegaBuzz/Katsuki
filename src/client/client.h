#ifndef __CLIENT_H
#define __CLIENT_H



struct IP_PORT{
    char *ip;
    int port;
    char *buffer;
    int buffer_len;
};

void* client_awk(void *ip_port);

#endif