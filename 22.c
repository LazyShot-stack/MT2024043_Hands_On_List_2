/*
============================================================================
Name : 22.c
Author : Dhruvik Patel - MT2024043
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    int fifo_fd;
    char fifo_path[] = "fifo_22";
    fd_set read_fds;
    struct timeval timeout;
    int ret;
    if (mkfifo(fifo_path, 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }
    fifo_fd = open(fifo_path, O_RDONLY);
    if (fifo_fd == -1) {
        perror("open");
        exit(1);
    }
    printf("Waiting for data in the FIFO...\n");
    FD_ZERO(&read_fds);
    FD_SET(fifo_fd, &read_fds);
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    ret = select(fifo_fd + 1, &read_fds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select");
        exit(1);
    } else if (ret == 0) {
        printf("Timeout: No data received within 10 seconds.\n");
    } else {
        if (FD_ISSET(fifo_fd, &read_fds)) {
            char buffer[1024];
            int bytes_read = read(fifo_fd, buffer, sizeof(buffer));
            if (bytes_read == -1) {
                perror("read");
                exit(1);
            }
            printf("Data received from FIFO: %s\n", buffer);
        }
    }

    close(fifo_fd);
    return 0;
}


/*
Hello Fifo1
Waiting for data in the FIFO...
Data received from FIFO: Hello, FIFO!�
*/

