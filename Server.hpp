#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>

class Server{
private:
  int socket_fd = -1;
  struct sockaddr socket_address;
  unsigned int addr_len;
public:
  Server();
  ~Server();
  int init(int port);
  int start();
  int loop();
};
