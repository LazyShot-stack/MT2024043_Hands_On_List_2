
/*
============================================================================
Name : 05e.c

Author : Dhruvik Patel

Description : Write a program to print the system limitation of
    // e. Size of a page (in bytes)
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <limits.h>
#include <sys/resource.h>

int main() {
    long page_size = sysconf(_SC_PAGESIZE);
    if (page_size == -1) {
        perror("Error getting size of a page");
    } else {
        printf("Size of a page: %ld bytes\n", page_size);
    }
    return 0;
}
//Size of a page: 4096 bytes

