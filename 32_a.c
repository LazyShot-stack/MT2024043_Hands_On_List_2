/*
============================================================================
Name : 32_a.c
Author : Dhruvik Patel - MT2024043
Description : Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_TICKETS 100
int t_count = 0;
sem_t ticket_semaphore;
void* generate_ticket(void* arg) {
    int* thread_id = (int*)arg;

    for (int i = 0; i < 7; i++) {
        sem_wait(&ticket_semaphore);
        printf("Thread %d generated ticket #%d\n", *thread_id, t_count);
        t_count++;
        sem_post(&ticket_semaphore);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3]; // Create 3 threads
    int thread_ids[3] = {1, 2, 3};
    sem_init(&ticket_semaphore, 0, 1);
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, generate_ticket, &thread_ids[i]);
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&ticket_semaphore);
    return 0;
}

/*
Thread 1 generated ticket #0
Thread 1 generated ticket #1
Thread 1 generated ticket #2
Thread 1 generated ticket #3
Thread 1 generated ticket #4
Thread 1 generated ticket #5
Thread 1 generated ticket #6
Thread 2 generated ticket #7
Thread 2 generated ticket #8
Thread 2 generated ticket #9
Thread 2 generated ticket #10
Thread 2 generated ticket #11
Thread 2 generated ticket #12
Thread 2 generated ticket #13
Thread 3 generated ticket #14
Thread 3 generated ticket #15
Thread 3 generated ticket #16
Thread 3 generated ticket #17
Thread 3 generated ticket #18
Thread 3 generated ticket #19
Thread 3 generated ticket #20
*/
