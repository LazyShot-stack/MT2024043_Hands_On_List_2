/*
============================================================================
Name : 32_b.c
Author :Dhruvik Patel - MT2024043
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

#define SHARED_MEMORY_SIZE 7

int shared_memory[SHARED_MEMORY_SIZE];
sem_t semaphore;

void* write_to_shared_memory(void* arg) {
    int* data = (int*)arg;
    for (int i = 0; i < SHARED_MEMORY_SIZE; i++) {
        sem_wait(&semaphore);
        shared_memory[i] = *data;
        printf("Thread wrote %d to shared memory at index %d\n", *data, i);
        sem_post(&semaphore);
    }
    pthread_exit(NULL);
}

int main() {
    int data_to_write = 52;
    pthread_t thread1, thread2;
    sem_init(&semaphore, 0, 1);
    pthread_create(&thread1, NULL, write_to_shared_memory, &data_to_write);
    pthread_create(&thread2, NULL, write_to_shared_memory, &data_to_write);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    sem_destroy(&semaphore);

    return 0;
}
/*
Thread wrote 52 to shared memory at index 0
Thread wrote 52 to shared memory at index 1
Thread wrote 52 to shared memory at index 2
Thread wrote 52 to shared memory at index 3
Thread wrote 52 to shared memory at index 4
Thread wrote 52 to shared memory at index 5
Thread wrote 52 to shared memory at index 6
Thread wrote 52 to shared memory at index 0
Thread wrote 52 to shared memory at index 1
Thread wrote 52 to shared memory at index 2
Thread wrote 52 to shared memory at index 3
Thread wrote 52 to shared memory at index 4
Thread wrote 52 to shared memory at index 5
Thread wrote 52 to shared memory at index 6
*/
