/*
============================================================================
Name : 21_b.c
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
    mkfifo("fifo1", 0666);
    fd = open("fifo1", O_RDWR);
    char buffer[100];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead > 0) 
    {
        buffer[bytesRead] = '\0;
        printf("Received message: %s\n", buffer);
        char response[] = "Message received!";
        write(fd, response, sizeof(response));
    }
    close(fd);
    unlink("fifo1");
    return 0;
}

//Wrote message to FIFO: Hello, FIFO!

