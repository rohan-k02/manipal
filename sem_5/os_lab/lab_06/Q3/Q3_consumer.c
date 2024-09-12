#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/my_fifo2"
#define BUFFER_SIZE 256  // Adjust buffer size to accommodate input strings

int main() {
    int pipe_fd;
    int res;
    char buffer[BUFFER_SIZE];  // Buffer to store data read from the FIFO
    int bytes_read = 0;

    // Open FIFO for reading
    printf("Consumer process %d opening FIFO O_RDONLY\n", getpid());
    pipe_fd = open(FIFO_NAME, O_RDONLY);
    if (pipe_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read from FIFO
    while ((res = read(pipe_fd, buffer, BUFFER_SIZE - 1)) > 0) {  // Leave space for null terminator
        buffer[res] = '\0';  // Null-terminate the string
        bytes_read += res;
        printf("Received: %s\n", buffer);
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
