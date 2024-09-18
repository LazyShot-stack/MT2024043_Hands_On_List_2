/*
============================================================================
Name : 20_b.c
Author : Dhruvik Patel - MT2024043
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
============================================================================
*/


//Reader
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
int main()
{
    int fd = open("fifo_one", O_RDONLY);
    char buff[100];
    int rd_bytes = read(fd, buff, sizeof(buff));
    buff[rd_bytes] = '\0';
    printf("Reader received: %s\n",buff);
    close(fd);
    unlink("fifo_one");
    return 0;
}
