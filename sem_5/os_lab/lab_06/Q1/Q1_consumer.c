/* Q1. Write a producer and consumer program in C using the FIFO queue. The producer
should write a set of 4 integers into the FIFO queue and the consumer should display
the 4 integers. */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/my_fifo2"
#define BUFFER_SIZE sizeof(int)  // Size of one integer

int main() {
    int pipe_fd;
    int res;
    int num;
    int bytes_read = 0;

    // Open FIFO for reading
    printf("Consumer process %d opening FIFO O_RDONLY\n", getpid());
    pipe_fd = open(FIFO_NAME, O_RDONLY);
    if (pipe_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read from FIFO
    while ((res = read(pipe_fd, &num, BUFFER_SIZE)) > 0) {
        bytes_read += res;
        printf("Received: %d\n", num);
    }

    if (res == -1) {
        perror("read");
        close(pipe_fd);
        exit(EXIT_FAILURE);
    }

    // Close FIFO
    close(pipe_fd);
    // Remove FIFO file
    unlink(FIFO_NAME);
    printf("Consumer process %d finished, %d bytes read\n", getpid(), bytes_read);
    exit(EXIT_SUCCESS);
}

