// child.c
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

    // Wait until the parent writes the alphabet
    while (shared_stuff->written_by_you == 0) {
        sleep(1);
    }

    // Read the alphabet from shared memory
    char alphabet = shared_stuff->some_text[0];
    printf("Parent sent: %c\n", alphabet);

    // Calculate the next alphabet
    if (alphabet >= 'a' && alphabet < 'z') {
        alphabet++;
    } else if (alphabet >= 'A' && alphabet < 'Z') {
        alphabet++;
    } else if (alphabet == 'z') {
        alphabet = 'a';
    } else if (alphabet == 'Z') {
        alphabet = 'A';
    } else {
        printf("Invalid input\n");
    }

    // Write the next alphabet to shared memory
    shared_stuff->some_text[0] = alphabet;
    shared_stuff->written_by_you = 0;

    // Detach from shared memory
    if (shmdt(shared_memory) == -1) {
        fprintf(stderr, "shmdt failed\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
