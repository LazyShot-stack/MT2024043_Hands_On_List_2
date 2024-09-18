
/*
============================================================================
Name : 05f.c

Author : Dhruvik Patel

Description : Write a program to print the system limitation of
    // f. Total number of pages in physical memory
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <limits.h>
#include <sys/resource.h>

int main() {
    long total_pages = sysconf(_SC_PHYS_PAGES);
    if (total_pages == -1) {
        perror("Error getting total number of pages in physical memory");
    } else {
        printf("Total number of pages in physical memory: %ld\n", total_pages);
    }
    return 0;
}
//Total number of pages in physical memory: 2000547

