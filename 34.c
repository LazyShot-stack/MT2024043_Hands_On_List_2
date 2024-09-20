/*
============================================================================
Name : 34.c
Author :Dhruvik Patel - MT2024043
Description : Write a program to create a concurrent server.
a. use fork
b. use pthread_create
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 12346
#define SERVER_IP "127.0.0.1"

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char message[1024];
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }
    while (1) {
        printf("Enter a message: ");
        fgets(message, sizeof(message), stdin);
        send(client_socket, message, strlen(message), 0);
        recv(client_socket, message, sizeof(message), 0);
        printf("Server says: %s", message);
        int bytes_received = recv(client_socket, message, sizeof(message), 0);
        if (bytes_received <= 0) {
            printf("Server disconnected.\n");
            break;
        }
        message[bytes_received] = '\0';
    }

    close(client_socket);

    return 0;
}

/*
Enter a message: Hello   
Server says: Hello
*/
