
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAX_LEN 0xFFFF

int main () {
    FILE *html_data = fopen("socket.html", "r");

    char *response_data = calloc(MAX_LEN, sizeof(char));

    if (fgets(response_data, MAX_LEN, html_data) == NULL) {
        perror("");
        exit(1);
    }

    char http_header[] = "HTTP/1.1 200 OK\r\n";
    strcat(response_data, http_header);


    //Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    //define the address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8001);
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr.s_addr);

    bind(server_socket, (struct sockaddr *) &server_address,  sizeof(server_address));
    
    listen(server_socket, 5);

    int client_socket;
    while (1) {
        client_socket = accept(server_socket, NULL, NULL);
        send(client_socket, http_header, sizeof(char) * strlen(http_header), 0);
        close(client_socket);
    }
    fclose(html_data);

    return 0;
}