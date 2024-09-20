/*
============================================================================
Name : 13b.c
Author : Dhruvik Patel - MT2024043
Description : Write two programs: the second program will send the signal (using kill system call).
============================================================================
*/

#include <stdio.h>
#include <signal.h>
int main(void) {
    printf("Enter the PID to send SIGSTOP signal to: ");
    int pid;
    scanf("%d", &pid);
    if (kill(pid, SIGSTOP) == -1) {
        perror("Could not send the SIGSTOP signal");
        return 1;
    }
    printf("SIGSTOP signal sent successfully\n");
}

/*
Enter the PID to send SIGSTOP signal to: 13660
SIGSTOP signal sent successfully
*/


