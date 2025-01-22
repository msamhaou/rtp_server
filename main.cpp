#include <iostream>
#include "Server.hpp"
#include <string>
#include <ctime>

int main (int argc, char *argv[]) {
  if (!argv[1])
    return -1;

  int port = std::stoi(argv[1]);
  time_t timestamp;
  int sequence = 0;
  Server server = Server();

  server.init(port);
  while (1){
    // RtpHeader rtp = RtpHeader(2, 1, 5, 1, 2, 116, sequence++);
    // time(&timestamp);
    // rtp.set_timestamp(timestamp);
    // rtp.set_ssrc_identifier(45555);
    // std::string hello = std::string("Hello");
    ts test;
    test.i = 100;
    test.j = 200;
    server.send((void *)&test);
    void * received = server.receive();
    // ts * t = 
    // std::cout << received << "\n";
  }
  return 0;
}
