
/*
============================================================================
Name : 05d.c

Author : Dhruvik Patel

Description : Write a program to print the system limitation of
    // d. Maximum number of open files
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <limits.h>
#include <sys/resource.h>

int main() {

    struct rlimit rlim;
    if (getrlimit(RLIMIT_NOFILE, &rlim) == -1) {
        perror("Error getting maximum number of open files");
    } else {
        printf("Maximum number of open files: %lu\n", rlim.rlim_cur);
    }
    return 0;
}

//Maximum number of open files: 1024

