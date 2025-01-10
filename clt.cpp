// Client side implementation of UDP client-server model 
#include <bits/stdc++.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

class Client {
	struct sockaddr socket_address;
	int sock = -1;
	size_t addr_len;
public:
	Client(int port);
	int send_msg(std::string);
	int recv_msg();
};

Client::Client(int port){
	this->sock = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in addr;
		addr.sin_port = htons(port);
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = INADDR_ANY;

	this->addr_len = sizeof(addr);
	memcpy(&this->socket_address, &addr, sizeof(addr));
}

int Client::send_msg(std::string msg){
	if (sendto(this->sock, msg.c_str(), msg.length(), MSG_CONFIRM, &this->socket_address, this->addr_len) < 0)
	{
		perror("sendto: ");
		exit(-1);
	}
	return 0;
}



// Driver code 
int main(int ac, char *argv[]) { 

	if (!argv[1])
		return -1;
	int port = std::stoi(argv[1]);
	Client clt = Client(port);

	while (1){
		std::string msg;
		std::getline(std::cin, msg);
		std::cout << (msg) << std::endl;
		clt.send_msg(msg);
		std::cout << "msg sent \n";
	}
}
