/*
============================================================================
Name : 10c.c
Author : Dhruvik Patel - MT2024043
Description : Write a separate program using sigaction system call to catch the following signals.
    c. SIGFPE
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigfpeHandler(int sig) {
    printf("Caught SIGFPE and exiting the process...\n");
    exit(EXIT_FAILURE);
}

int main(void) {
    struct sigaction sga;

    sga.sa_handler = sigfpeHandler;

    sigemptyset(&sga.sa_mask);

    sga.sa_flags = 0;

    if (sigaction(SIGFPE, &sga, NULL) == -1) {
        perror("Could not set SIGFPE Handler");
        exit(EXIT_FAILURE);
    }

    int x = 0;
    int y = 1;

    int z = y / x;

    printf("%d", z);
}

/*
Caught SIGFPE and exiting the process...
*/
