
/*
============================================================================
Name : 05g.c

Author : Dhruvik Patel

Description : Write a program to print the system limitation of
    // g. Number of currently available pages in physical memory
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <limits.h>
#include <sys/resource.h>

int main() {
    long avail_pages = sysconf(_SC_AVPHYS_PAGES);
    if (avail_pages == -1) {
        perror("Error getting number of currently available pages in physical memory");
    } else {
        printf("Number of currently available pages in physical memory: %ld\n", avail_pages);
    }

    return 0;
}
//Number of currently available pages in physical memory: 180549

