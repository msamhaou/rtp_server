// Client side implementation of UDP client-server model 
#include <bits/stdc++.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>
#include "RTP.hpp"

class Client {
	struct sockaddr socket_address;
	int socket_fd = -1;
	unsigned int addr_len;
public:
	Client(int port);
	int send(void *) const;
	void * receive();
};

Client::Client(int port){
	this->socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (this->socket_fd == -1){
		perror("socket : ");
		exit(1);
	}
	struct sockaddr_in addr;
		addr.sin_port = htons(port);
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = INADDR_ANY;

	this->addr_len = sizeof(addr);
	memcpy(&this->socket_address, &addr, sizeof(addr));
}

int Client::send(void * packet) const{
  if (sendto(this->socket_fd, packet, RtpHeader::buffer_len, MSG_CONFIRM, &this->socket_address, this->addr_len) < 0)
	{
		perror("sendto: ");
		return -1;
	}
	return 0;
}


void * Client::receive(){
  void * buff;

  buff = malloc(RtpHeader::buffer_len * sizeof(char));
  int n = recvfrom(this->socket_fd, buff, RtpHeader::buffer_len, MSG_WAITALL, &this->socket_address, &this->addr_len); 
    if (n  < 0)
    {
      perror("recv");
      exit(-1);
    }
    return buff;
}


// Driver code 
int main(int ac, char *argv[]) { 

	if (!argv[1])
		return -1;
	int port = std::stoi(argv[1]);
	Client s = Client(port);

	ts test;
	test.i = 200;
	test.j = 400;
	while (1){
		s.send((void * )&test);
		void * received = s.receive();

		ts * r = (ts *)received;
		std::cout << r->j << std::endl;
	}
}
