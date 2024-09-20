/*
============================================================================
Name : 34_a.c
Author : Dhruvik Patel - MT2024043
Description : Write a program to create a concurrent server.
a. use fork
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#define PORT 12346
#define MAX_CONNECTIONS 5

void handle_client(int client_socket) {
    char buffer[1024];
    int bytes_received;
    while (1) {
        bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            close(client_socket);
            exit(0);
        }
        buffer[bytes_received] = '\0';
        printf("Received: %s", buffer);
        send(client_socket, buffer, strlen(buffer), 0);
    }
}
int main() {
  //  signal(SIGINT, sigint_handler);
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    pid_t child_pid;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(1);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(1);
    }
    if (listen(server_socket, MAX_CONNECTIONS) == 0) {
        printf("Server listening on port %d\n", PORT);
    } else {
        perror("Listening failed");
        exit(1);
    }
    while (1) {
        addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
        if (client_socket < 0) {
            perror("Accepting connection failed");
            continue;
        }
        child_pid = fork();
        if (child_pid == 0) {
            close(server_socket);
            handle_client(client_socket);
            break;
        } else if (child_pid > 0) {
            close(client_socket);
        } else {
            perror("Forking failed");
        }
    }
    close(server_socket);
    return 0;
}

/*
Server listening on port 12346
Received: Hello
*/


