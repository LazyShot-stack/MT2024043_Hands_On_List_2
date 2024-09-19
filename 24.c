/*
============================================================================
Name : 24.c
Author : Dhruvik Patel - MT2024043
Description : Write a program to create a message queue and print the key and message queue id.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main()
{
    key_t key;
    int msgid;
    key = ftok(".", 'Y');
    msgid = msgget(key, 0666 | IPC_CREAT);
    printf("Key: %x\n", (unsigned int)key);
    printf("Message Queue ID: %d\n", msgid);
    return 0;
}

/*
Key: 591827ca
Message Queue ID: 0
*/
