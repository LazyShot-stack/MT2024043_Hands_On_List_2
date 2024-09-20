/*
============================================================================
Name : 13a.c
Author : Dhruvik Patel - MT2024043
Description : Write two programs: first program is waiting to catch SIGSTOP signal,
Find out whether the first program is able to catch the signal or not.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Waiting for SIGSTOP \nProcess PID: %d\n", getpid());
    while(1) {sleep(1);}
}

/*
Waiting for SIGSTOP
Process PID: 13660
*/
