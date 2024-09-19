/*
============================================================================
Name : 21_a.c
Author : Dhruvik Patel - MT2024043
Description : Write two programs so that both can communicate by FIFO -Use two way communication.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
int main() 
{
    int fd;
    fd = open("fifo1", O_RDWR|O_CREAT, 0777);
    char message[] = "Hello from Writer!\n";
    write(fd, message, sizeof(message));
    char response[100];
    int bytesRead = read(fd, response, sizeof(response));
    if (bytesRead > 0) 
    {
        response[bytesRead] = '\0';
        printf("Received response: %s\n", response);
    }
    close(fd);
    return 0;
}

//Received message: Hello from Writer!

