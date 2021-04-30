//A program where the server listens for any clients
//and sends data to the client
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>


#define MAX_LEN 0xFFFF

int main () {

	char *server_message = "Welcome to the server\n";
	fopen("");
	
	//Create a server socket
	int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	//Specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(65535);
	server_address.sin_addr.s_addr = INADDR_ANY;

	//Connect the socket to the specified IP and port
	bind(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address));
	
	//Listen to n number of clients and get the ID of the client
	listen(socket_fd, 5);
	int client_socket = 0;
	
	while (1) {
		accept(socket_fd, NULL, NULL);
		//send the message
		send(client_socket, server_message, strlen(server_message) * sizeof(char), 0);
		close(client_socket);
	}
	close(socket_fd);

	return 0;
}
