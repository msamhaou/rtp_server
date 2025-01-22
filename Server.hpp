#pragma once
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include "RTP.hpp"



class Server{
private:
  int socket_fd = -1;
  struct sockaddr socket_address;
  unsigned int addr_len;
public:
  Server();
  ~Server();
  int init(const int & port);
  int send(void *) const;
  void* receive();
};

// const int RtpHeader::buffer_len;