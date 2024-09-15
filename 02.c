/*
============================================================================
Name : 02.c

Author : Dhruvik Patel

Description : Write a program to print the system resource limits. Use getrlimit system call.

============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

void print_rlimit(int resource, const char *name) {
    struct rlimit limit;
    
    if (getrlimit(resource, &limit) == 0) {
        printf("%-20s: Soft Limit = %lu, Hard Limit = %lu\n", name, limit.rlim_cur, limit.rlim_max);
    } else {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }
}

int main() {
    print_rlimit(RLIMIT_CPU, "CPU Time (seconds)");
    print_rlimit(RLIMIT_FSIZE, "Max File Size (bytes)");
    print_rlimit(RLIMIT_DATA, "Max Data Segment Size (bytes)");
    print_rlimit(RLIMIT_STACK, "Max Stack Size (bytes)");
    print_rlimit(RLIMIT_CORE, "Max Core File Size (bytes)");
    print_rlimit(RLIMIT_RSS, "Max Resident Set Size (bytes)");
    print_rlimit(RLIMIT_NOFILE, "Max Number of Open Files");
    print_rlimit(RLIMIT_MEMLOCK, "Max Locked Memory (bytes)");
    print_rlimit(RLIMIT_AS, "Max Address Space (bytes)");
    print_rlimit(RLIMIT_NPROC, "Max Number of Processes");
    print_rlimit(RLIMIT_LOCKS, "Max Number of File Locks");

    return 0;
}

/*
CPU Time (seconds)  : Soft Limit = 18446744073709551615, Hard Limit = 18446744073709551615
Max File Size (bytes): Soft Limit = 18446744073709551615, Hard Limit = 18446744073709551615
Max Data Segment Size (bytes): Soft Limit = 18446744073709551615, Hard Limit = 18446744073709551615
Max Stack Size (bytes): Soft Limit = 8388608, Hard Limit = 18446744073709551615
Max Core File Size (bytes): Soft Limit = 0, Hard Limit = 18446744073709551615
Max Resident Set Size (bytes): Soft Limit = 18446744073709551615, Hard Limit = 18446744073709551615
Max Number of Open Files: Soft Limit = 1024, Hard Limit = 1048576
Max Locked Memory (bytes): Soft Limit = 1024278528, Hard Limit = 1024278528
Max Address Space (bytes): Soft Limit = 18446744073709551615, Hard Limit = 18446744073709551615
Max Number of Processes: Soft Limit = 30965, Hard Limit = 30965
Max Number of File Locks: Soft Limit = 18446744073709551615, Hard Limit = 18446744073709551615
*/
