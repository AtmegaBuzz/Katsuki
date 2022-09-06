#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa//inet.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

char buffer[BUFFER_SIZE];

void* recv_msg(void *serv_sock_arg){

    int server_sock = *((int *)serv_sock_arg);
    
    while(1){
        bzero(buffer, 1024);
        recv(server_sock, buffer, 1024, 0);
        printf("Message: %s\n",buffer);      
    }
    
}

int main(){

    char *ip = "127.0.0.1";
    int port = 9909;

    int server_sock;
    struct sockaddr_in server_addr;

    socklen_t addr_size;
    char buffer[1024];
    
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

    pthread_t recv_thread;
    pthread_create(&recv_thread,NULL,&recv_msg,&server_sock);

    while(1){
        bzero(buffer,1024);
        scanf("%s",&buffer);
        send(server_sock,buffer,strlen(buffer),0);

        if (strcmp(buffer,"exit")==0){
            printf("[-]Disconnected from server\n");
            exit(1);
        }
    }

    return 0;
}
