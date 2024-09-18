
/*
============================================================================
Name : 05b.c

Author : Dhruvik Patel

Description : Write a program to print the system limitation of
    // b. Maximum number of simultaneous processes per user ID
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <limits.h>
#include <sys/resource.h>

int main() {
    long max_processes = sysconf(_SC_CHILD_MAX);
    if (max_processes == -1) {
        perror("Error getting maximum number of simultaneous processes per user ID");
    } else {
        printf("Maximum number of simultaneous processes per user ID: %ld\n", max_processes);
    }
    return 0;
}

//Maximum number of simultaneous processes per user ID: 30965
