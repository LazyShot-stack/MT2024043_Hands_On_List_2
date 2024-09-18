/*
============================================================================
Name : 20_a.c
Author : Dhruvik Patel - MT2024043
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
============================================================================
*/

//Writer
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
int main()
{
    mkfifo("fifo_one", 0777);
    int fd = open("fifo_one", O_WRONLY);
    char data[] = "Hello! My name is Dhruvik.\n";
    write(fd, data, sizeof(data));
    printf("Message sent by the Writer: %s\n", data);
    close(fd);
    return 0;
}

//Message sent by the Writer: Hello! My name is Dhruvik.
//Reader received: Hello! My name is Dhruvik.

