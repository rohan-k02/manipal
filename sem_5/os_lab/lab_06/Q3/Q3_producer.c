/* Q3. Write a C program to implement one side of FIFO. */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/my_fifo2"
#define BUFFER_SIZE 256  // Adjust buffer size to accommodate input strings

int main(int argc, char *argv[]) {
    int pipe_fd;
    int res;

    // Check for command-line argument
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create the FIFO if it doesn't exist
    if (access(FIFO_NAME, F_OK) == -1) {
        res = mkfifo(FIFO_NAME, 0666);  // Set permissions to 0666 for read/write access
        if (res != 0) {
            perror("mkfifo");
            exit(EXIT_FAILURE);
        }
    }

    // Open FIFO for writing
    printf("Producer process %d opening FIFO O_WRONLY\n", getpid());
    pipe_fd = open(FIFO_NAME, O_WRONLY);
    if (pipe_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Write the string to FIFO
    res = write(pipe_fd, argv[1], strlen(argv[1]) + 1);  // Include null terminator
    if (res == -1) {
        perror("write");
        close(pipe_fd);
        exit(EXIT_FAILURE);
    }

    // Close FIFO
    close(pipe_fd);
    printf("Producer process %d finished\n", getpid());
    exit(EXIT_SUCCESS);
}
