/*
============================================================================
Name : 30.c
Author : Dhruvik Patel - MT2024043
Description : Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    key_t key = ftok("shmfile", 65); 
    int shmid;
    char *data;
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    data = (char *)shmat(shmid, NULL, 0);
    if (data == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }
    strcpy(data, "Hello, Shared Memory!");
    printf("Data written to shared memory: %s\n", data);
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }
    data = (char *)shmat(shmid, NULL, SHM_RDONLY);
    if (data == (char *)(-1)) {
        perror("shmat (read-only)");
        exit(1);
    }
    printf("Data read from shared memory (read-only): %s\n", data);
    printf("Attempting to overwrite in read-only mode...\n");
    strcpy(data, "Attempt to overwrite");
    printf("Data after overwrite attempt: %s\n", data); 
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }
    printf("Shared memory segment marked for deletion.\n");

    return 0;
}

/*
Data written to shared memory: Hello, Shared Memory!
Data read from shared memory (read-only): Hello, Shared Memory!
Attempting to overwrite in read-only mode...
Segmentation fault (core dumped)
*/
