
/*
============================================================================
Name : 05a.c

Author : Dhruvik Patel

Description : Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <limits.h>
#include <sys/resource.h>

int main() {
    long max_arg_len = sysconf(_SC_ARG_MAX);
    if (max_arg_len == -1) {
        perror("Error getting max length of arguments to exec family of functions");
    } else {
        printf("Maximum length of arguments to exec family of functions: %ld\n", max_arg_len);
    }
    return 0;
}

//Maximum length of arguments to exec family of functions: 2097152

