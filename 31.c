/*
============================================================================
Name : 31.c
Author : Dhruvik Patel - MT2024043
Description : Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

int main() {
    // Create and initialize a binary semaphore
    sem_t binary_semaphore;
    if (sem_init(&binary_semaphore, 0, 1) == -1) {
        perror("sem_init (binary)");
        exit(EXIT_FAILURE);
    }
    // Create and initialize a counting semaphore with an initial value of 7
    sem_t counting_semaphore;
    if (sem_init(&counting_semaphore, 0, 7) == -1) {
        perror("sem_init (counting)");
        exit(EXIT_FAILURE);
    }
    // Perform some operations using the semaphores
    printf("Binary Semaphore: Created and Initialized.\n");
    printf("Counting Semaphore: Created and Initialized with an initial value of 7.\n");
    // Destroy the semaphores when done
    sem_destroy(&binary_semaphore);
    sem_destroy(&counting_semaphore);

    return 0;
}

/*
Binary Semaphore: Created and Initialized.
Counting Semaphore: Created and Initialized with an initial value of 7.
*/
