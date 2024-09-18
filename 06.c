/*
============================================================================
Name : 04.c

Author : Dhruvik Patel

Description : Write a simple program to create three threads.
============================================================================
*/

#include <pthread.h>
#include <stdio.h>

void* thread_function(void* arg) {
    printf("Hello from Thread %d\n", *((int*)arg));
    return NULL;
}

int main() {
    pthread_t threads[3];
    int i;

    for (i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_function, &i);
        pthread_join(threads[i], NULL);
    }

    return 0;
}

/*
Hello from Thread 0
Hello from Thread 1
Hello from Thread 2
*/
