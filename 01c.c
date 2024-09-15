/*
============================================================================
Name : 01c.c

Author : Dhruvik Patel

Description :
Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
    a. ITIMER_PROF

Date: 9th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <signal.h>

void timer_handler(int signum) {
    printf("Profile Timer expired\n");
}

int main() {
    struct itimerval timer;

    signal(SIGPROF, timer_handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 0;

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    while (1);

    return 0;
}
/*
Profile Timer expired
...
*/
