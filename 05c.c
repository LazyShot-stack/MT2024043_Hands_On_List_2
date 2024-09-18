
/*
============================================================================
Name : 05c.c

Author : Dhruvik Patel

Description : Write a program to print the system limitation of
    // c. Number of clock ticks (jiffies) per second
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <limits.h>
#include <sys/resource.h>

int main() {

    long clock_ticks = sysconf(_SC_CLK_TCK);
    if (clock_ticks == -1) {
        perror("Error getting number of clock ticks per second");
    } else {
        printf("Number of clock ticks per second: %ld\n", clock_ticks);
    }
    return 0;
}

//Number of clock ticks per second: 100

