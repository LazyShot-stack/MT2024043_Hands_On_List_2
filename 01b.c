/*
============================================================================
Name : 01b.c

Author : Dhruvik Patel

Description :
Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
    a. ITIMER_VIRTUAL

Date: 9th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>

void timer_handler(int signum) {
    printf("Virtual Timer expired\n");
}

int main() {
    struct itimerval timer;

    signal(SIGVTALRM, timer_handler);

    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1);

    return 0;
}
/*
Virtual Timer expired
...
*/
