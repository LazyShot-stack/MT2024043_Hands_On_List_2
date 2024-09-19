/*
============================================================================
Name : 32.c
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
#include <unistd.h>

#define NUM_RESOURCES 2

sem_t resource_semaphores[NUM_RESOURCES];

void* access_resource(void* arg) {
    int resource_id = *((int*)arg);

    sem_wait(&resource_semaphores[resource_id]);
    printf("Thread accessed resource %d\n", resource_id);
    sleep(2);
    sem_post(&resource_semaphores[resource_id]);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_RESOURCES];
    int thread_args[NUM_RESOURCES] = {0, 1};
    for (int i = 0; i < NUM_RESOURCES; i++) {
        sem_init(&resource_semaphores[i], 0, 1); 
    }
    for (int i = 0; i < NUM_RESOURCES; i++) {
        pthread_create(&threads[i], NULL, access_resource, &thread_args[i]);
    }
    for (int i = 0; i < NUM_RESOURCES; i++) {
        pthread_join(threads[i], NULL);
    }
    for (int i = 0; i < NUM_RESOURCES; i++) {
        sem_destroy(&resource_semaphores[i]);
    }
    return 0;
}

/*
Thread accessed resource 0
Thread accessed resource 1
*/

