#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/my_fifo2"
#define BUFFER_SIZE 64

int main() {
    int pipe_fd;
    int res;
    const int data[] = {10, 20, 30, 40};
    const int num_integers = sizeof(data) / sizeof(data[0]);

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

    // Write integers to FIFO
    for (int i = 0; i < num_integers; i++) {
        res = write(pipe_fd, &data[i], sizeof(data[i]));

        if (res == -1) { 
            perror("write");
            close(pipe_fd);
            exit(EXIT_FAILURE);
        }
    }

    // Close FIFO
    close(pipe_fd);
    printf("Producer process %d finished\n", getpid());
    exit(EXIT_SUCCESS);
}
