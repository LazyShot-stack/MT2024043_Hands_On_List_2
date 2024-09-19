/*
============================================================================
Name : 27_a.c
Author : Dhruvik Patel - MT2024043
Description : Write a program to receive messages from the message queue.
	      a. with 0 as a flag
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct  msg_buffer {
    long msg_type;
    char msg_text[512];
};
int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;
    key = ftok(".", 'H');
    msgid = msgget(key, 0666);
    while (1) {
        msgrcv(msgid, (void*)&message, 512, 0, 0);
        printf("Received Message Type: %ld\n", message.msg_type);
        printf("Message Text: %s\n", message.msg_text);
        printf("----------------------------\n");
        if (message.msg_type == 999) {
            printf("Received an exit message. Exiting the loop.\n");
            break; // Exit the loop
        }
    }
    exit(0);
    return 0;
}

/*
Received Message Type: 3629693776660547328
Message Text: .2.6
----------------------------
Received Message Type: 3629693776660547328
Message Text: .2.6
----------------------------
*/
