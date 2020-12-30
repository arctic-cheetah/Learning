
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAX_LEN 0xFFFF

int main (int argc, char **argv) {
    char *address = argv[1];

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    //connect
    struct sockaddr_in remote_address;
    remote_address.sin_family = AF_INET;
    remote_address.sin_port = htons(8001);
    inet_aton(address, &remote_address.sin_addr);

    connect(client_socket, (struct sockaddr *) &remote_address, sizeof(remote_address));
    char request[] = "Get /HTTP1.1\r\n";
    char response[MAX_LEN] = {0};

    send(client_socket, request, sizeof(request), 0);
    recv(client_socket, response, sizeof(response), 0);

    printf("Response from server %s \n", response);
    close(client_socket);
    return 0;
}