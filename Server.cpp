#include "Server.hpp"
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <cstring>

Server::Server(){}
Server::~Server(){
  close(this->socket_fd);
}

int Server::init(int port){
  int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
  if (socket_fd < 0){
    perror("socket:");
    exit (-1);
  }
   
  this->socket_fd = socket_fd;
  struct sockaddr_in sockaddress;
    sockaddress.sin_family = AF_INET;
    sockaddress.sin_port = htons(port);
    sockaddress.sin_addr.s_addr = INADDR_ANY;
  
  memcpy(&this->socket_address, (sockaddr*)(&sockaddress), sizeof(sockaddr));
  this->addr_len = sizeof(sockaddress);
  if (bind(socket_fd, (sockaddr*)(&socket_address), this->addr_len) == -1 )
  {
    perror("bind");
    exit(-1);
  }
   

  return socket_fd;
}

int Server::loop(){
  char buffer[1024];
  while (1){
    int n = recvfrom(this->socket_fd, buffer, 1024, MSG_WAITALL, &this->socket_address, &this->addr_len); 
    if (n  < 0)
    {
      perror("recv");
      exit(-1);
    } 
    buffer[n] = '\0';
    printf("%s\n", buffer);
  }
    return 0;
}

int Server::start(){
   int running = 1;
  return this->loop();
}
