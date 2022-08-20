#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){

  char *ip = "127.0.0.1";
  int port = 9909;

  int server_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_size;
  char buffer[1024];
  int n;

  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0){
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");

  memset(&server_addr, '\0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);

  n = bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if (n < 0){
    perror("[-]Bind error");
    exit(1);
  }
  printf("[+]Bind to the port number: %d\n", port);

  listen(server_sock, 5);
  printf("Listening...\n");

  while(1){

    addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
    if(client_sock<0){
      perror("[-]Client Accept Failed\n");
      exit(1);
    }
    printf("[+]Client connected.\n");

    if(fork()==0){
      // close(server_sock);

      while(1){
        bzero(buffer, 1024);
        recv(client_sock, buffer, 1024, 0);
        if(strcmp(buffer,"exit")==0){
          printf("[-]Client Disconnected\n");
          close(client_sock);
          close(server_sock);
          exit(1);
        }
        else{
          printf("Client: %s\n", buffer);
        }
      }
    }
      
  }
  close(client_sock);
  close(server_sock);
  return 0;
}