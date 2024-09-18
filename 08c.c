/*
============================================================================
Name : 08c.c

Author : Dhruvik Patel

Description : Write a separate program using signal system call to catch the following signals.
c. SIGFPE
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigfpe_handler(int sig) {
    printf("Caught SIGFPE: Floating-point exception\n");
    exit(1);
}

int main() {
    signal(SIGFPE, sigfpe_handler);

    int x = 5 / 0;

    return 0;
}

//Caught SIGFPE: Floating-point exception

