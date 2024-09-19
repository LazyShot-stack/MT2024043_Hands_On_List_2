/*
============================================================================
Name : 25.c
Author : Dhruvik Patel - MT2024043
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <time.h>
int main() {
    key_t k;
    int mid;
    k = ftok(".", 'Y');
    mid = msgget(k, 0666 | IPC_CREAT);
    struct msqid_ds msq_info;
    msgctl(mid, IPC_STAT, &msq_info);
    printf("a. Access permission: %#o\n", msq_info.msg_perm.mode);
    printf("b. UID: %d, GID: %d\n", msq_info.msg_perm.uid, msq_info.msg_perm.gid);
    printf("c. Time of last message sent: %s", ctime(&msq_info.msg_stime));
    printf("d. Time of last message received: %s", ctime(&msq_info.msg_rtime));
    printf("e. Time of last change in the message queue: %s", ctime(&msq_info.msg_ctime));
    printf("f. Size of the queue: %lu bytes\n", (unsigned long)msq_info.msg_qbytes);
    printf("g. Number of messages in the queue: %lu\n", (unsigned long)msq_info.msg_qnum);
    printf("h. Maximum number of bytes allowed: %lu bytes\n", (unsigned long)msq_info.msg_qbytes);
    printf("i. PID of msgsnd: %d\n", msq_info.msg_lspid);
    printf("j. PID of msgrcv: %d\n", msq_info.msg_lrpid);
    return 0;
}
/*
a. Access permission: 0666
b. UID: 1000, GID: 1000
c. Time of last message sent: Thu Jan  1 05:30:00 1970
d. Time of last message received: Thu Jan  1 05:30:00 1970
e. Time of last change in the message queue: Thu Sep 19 09:14:05 2024
f. Size of the queue: 16384 bytes
g. Number of messages in the queue: 0
h. Maximum number of bytes allowed: 16384 bytes
i. PID of msgsnd: 0
j. PID of msgrcv: 0
*/
