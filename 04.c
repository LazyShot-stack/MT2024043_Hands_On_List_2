/*
============================================================================
Name : 03.c

Author : Dhruvik Patel

Description : Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

uint64_t rdtsc() {
    unsigned int lo, hi;
    __asm__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    uint64_t start, end;
    int i;
    start = rdtsc();
    for (i = 0; i < 100; i++) {
        getppid();
    }
    end = rdtsc();
    uint64_t elapsed = end - start;

    printf("Time taken to execute 100 getppid() calls: %lu clock cycles\n", elapsed);

    return 0;
}

// Time taken to execute 100 getppid() calls: 600769 clock cycles

