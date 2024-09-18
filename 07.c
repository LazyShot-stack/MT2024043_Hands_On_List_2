/*
============================================================================
Name : 07.c

Author : Dhruvik Patel

Description : Write a simple program to print the created thread ids.
============================================================================
*/

#include <pthread.h>
#include <stdio.h>

void* thread_function(void* arg) {
    printf("Thread ID: %lu\n", pthread_self());  
    return NULL;
}

int main() {
    pthread_t threads[3];
    int i;

    for (i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_function, NULL);
    }

    for (i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

/*
Thread ID: 139701281355456
Thread ID: 139701264570048
Thread ID: 139701272962752
*/
