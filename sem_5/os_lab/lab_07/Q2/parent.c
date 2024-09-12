/* Q2. Implement a parent process, which sends an English alphabet to a child process
using shared memory. The child process responds with the next English alphabet
to the parent. The parent displays the reply from the Child. */

// parent.c
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "shm_com.h"

int main() {
    void *shared_memory = (void *)0;
    struct shared_use_st *shared_stuff;
    int shmid;
    char alphabet;

    // Create shared memory
    shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
    if (shmid == -1) {
        fprintf(stderr, "shmget failed\n");
        exit(EXIT_FAILURE);
    }

    // Attach to the shared memory
    shared_memory = shmat(shmid, (void *)0, 0);
    if (shared_memory == (void *)-1) {
        fprintf(stderr, "shmat failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Memory attached at %p\n", shared_memory);
    shared_stuff = (struct shared_use_st *)shared_memory;

    // Initialize the shared memory control flag
    shared_stuff->written_by_you = 0;

    // Get an alphabet from the user
    printf("Enter an alphabet: ");
    scanf(" %c", &alphabet);

    // Write the alphabet to shared memory
    shared_stuff->some_text[0] = alphabet;
    shared_stuff->written_by_you = 1;

    // Wait for the child's response
    while (shared_stuff->written_by_you == 1) {
        sleep(1);
    }

    // Display the child's response
    printf("Child responded with: %c\n", shared_stuff->some_text[0]);

    // Detach and remove the shared memory
    if (shmdt(shared_memory) == -1) {
        fprintf(stderr, "shmdt failed\n");
        exit(EXIT_FAILURE);
    }
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        fprintf(stderr, "shmctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
