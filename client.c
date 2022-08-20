#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa//inet.h>


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
    printf("[+]Connected to server %d\n");

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