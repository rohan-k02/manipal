/* Q3. Write two programs named Interface and Display for the following problem.
Interface program
This program, when run, gives a prompt to the user as “Enter your message:”When the
user enters his/her message string and presses Enter, the program writes the message into
the shared memory, tells the Display to start processing,and then prompts the user again
for another message.
Display program
The process waits until a new message becomes available on the shared memory. Then it
reads the contents of the memory and prints it on the screen. It also clears the contents of
the shared memory when it has read the message. */


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
    char buffer[TEXT_SZ];

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

    while (1) {
        // Prompt user for a message
        printf("Enter your message: ");
        fgets(buffer, TEXT_SZ, stdin);
        
        // Remove newline character if present
        buffer[strcspn(buffer, "\n")] = 0;

        // Write the message to shared memory
        strncpy(shared_stuff->some_text, buffer, TEXT_SZ);
        shared_stuff->written_by_you = 1;

        // Wait for Display to clear the memory
        while (shared_stuff->written_by_you == 1) {
            sleep(1);
        }
    }

    // Detach from shared memory
    if (shmdt(shared_memory) == -1) {
        fprintf(stderr, "shmdt failed\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
