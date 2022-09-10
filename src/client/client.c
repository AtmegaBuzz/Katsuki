#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa//inet.h>
#include <pthread.h>
#include "client.h"



// void* recv_msg(void *serv_sock_arg){

//     int server_sock = *((int *)serv_sock_arg);
    
//     while(1){
//         bzero(buffer, 1024);
//         recv(server_sock, buffer, 1024, 0);
//         printf("Message: %s\n",buffer);      
//     }
    
// }


void* client_awk(void *ip_port){

    struct IP_PORT *p = (struct IP_PORT *) ip_port;

    char *ip = p->ip;
    int port = p->port;
    char *buffer = p->buffer;
    int buffer_len = p->buffer_len;

    int server_sock;
    struct sockaddr_in server_addr;

    socklen_t addr_size;
    
    server_sock = socket(AF_INET,SOCK_STREAM,0);
    if (server_sock<0){
        perror("[-]Socket Creation failed\n");
        exit(1);
    }

    printf("[+]Socket Created\n");

    memset(&server_addr,'\0',sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = inet_addr(ip);

    connect(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr));
    printf("[+]Connected to server\n");

    // pthread_t recv_thread;
    // pthread_create(&recv_thread,NULL,&recv_msg,&server_sock);

    while(1){

        if (buffer!=NULL && buffer[0]=='\0'){
            sleep(0.5);
            continue;
        }

        send(server_sock,buffer,strlen(buffer),0);
        

        if (strcmp(buffer,"exit")==0){
            printf("[-]Disconnected from server\n");
            exit(1);
        }
        bzero(buffer,buffer_len);
    }

}
