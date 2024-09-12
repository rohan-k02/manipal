/* Q2. Demonstrate creation, writing to, and reading from a pipe. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>  // for pipe(), write(), read()

int main(int argc, char **argv) {
    int n;
    int fd[2];
    char buf[1025];  // Buffer to store data read from the pipe
    char *data = "hello... this is sample data";

    // Create a pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Write data to the pipe
    if (write(fd[1], data, strlen(data)) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Read data from the pipe
    if ((n = read(fd[0], buf, 1024)) >= 0) {
        buf[n] = '\0';  // Null-terminate the string
        printf("Read %d bytes from the pipe: \"%s\"\n", n, buf);
    } else {
        perror("read");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
