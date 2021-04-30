//A program where the client receives data from the server

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAX_LEN 0xFFFF

int main () {
	
	//Create a socket
	int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	//Specify an address for the socket


	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	inet_pton(AF_INET, "192.168.0.22", &server_address.sin_addr.s_addr);

	//Error checking
	if ( connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
		perror("");
		return 0;
	}
	char *server_response = calloc(MAX_LEN, sizeof(char));

	//Receive data from the server
	recv(socket_fd, server_response, MAX_LEN * sizeof(char), 0);

	//Print the server's response
	printf("Received : %s", server_response);

	//Close the socket
	close(socket_fd);
	free(server_response);

	return 0;
}
