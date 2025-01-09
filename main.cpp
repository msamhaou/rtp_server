#include <iostream>
#include "Server.hpp"
#include <string>

int main (int argc, char *argv[]) {
  if (!argv[1])
    return -1;
  int port = std::stoi(argv[1]);
  Server server = Server();
  server.init(port);
  server.start();
  return 0;
}
