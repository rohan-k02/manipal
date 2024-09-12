/*
Q4. Write two programs, producer.c implementing a producer and consumer.c
implementing a consumer, that do the following:

Your product will sit on a shelf: that is an integer - a count of the items "on the shelf".
This integer may never drop below 0 or rise above 5.
Your producer sets the value of the count to 5. It is the producer program's
responsibility to stock product on the shelf, but not overstocked. The producer may
add one item to the shelf at a time, and must report to STDOUT every time another
item is added as well as the current shelf count.
Your consumer will remove one item from the shelf at a time, provided the item count
has not dropped below zero. The consumer will decrement the counter and report the
new value to STDOUT. Have your consumer report each trip to the shelf, in which
there are no items.
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/my_fifo"
#define MAX_COUNT 5

int main() {
    int pipe_fd;
    int shelf_count = 0;
    int res;

    // Create the FIFO if it doesn't exist
    if (access(FIFO_NAME, F_OK) == -1) {
        if (mkfifo(FIFO_NAME, 0666) != 0) {
            perror("mkfifo");
            exit(EXIT_FAILURE);
        }
    }

    // Open FIFO for writing
    pipe_fd = open(FIFO_NAME, O_WRONLY);
    if (pipe_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Stock items on the shelf
    while (shelf_count < MAX_COUNT) {
        shelf_count++;
        res = write(pipe_fd, &shelf_count, sizeof(shelf_count));
        if (res == -1) {
            perror("write");
            close(pipe_fd);
            exit(EXIT_FAILURE);
        }
        printf("Producer: Added 1 item. Current shelf count: %d\n", shelf_count);
        sleep(1);  // Simulate time taken to add an item
    }

    // Close FIFO
    close(pipe_fd);
    printf("Producer finished.\n");
    exit(EXIT_SUCCESS);
}
