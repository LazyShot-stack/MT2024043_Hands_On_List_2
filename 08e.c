/*
============================================================================
Name : 08e.c

Author : Dhruvik Patel

Description : Write a separate program using signal system call to catch the following signals.
e. SIGALRM (use setitimer system call)
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigalrm_handler(int sig) {
    printf("Caught SIGALRM: Timer expired (setitimer)\n");
}

int main() {
    signal(SIGALRM, sigalrm_handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 5;     
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;  
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1);

    return 0;
}

//Caught SIGALRM: Timer expired (setitimer)

