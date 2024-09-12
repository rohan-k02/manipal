#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/my_fifo"
#define MIN_COUNT 0

int main() {
    int pipe_fd;
    int shelf_count;
    int res;

    // Open FIFO for reading
    pipe_fd = open(FIFO_NAME, O_RDONLY);
    if (pipe_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Consume items from the shelf
    while (1) {
        res = read(pipe_fd, &shelf_count, sizeof(shelf_count));
        if (res == -1) {
            perror("read");
            close(pipe_fd);
            exit(EXIT_FAILURE);
        }
        if (res == 0) {
            break;  // FIFO closed by producer
        }

        if (shelf_count > MIN_COUNT) {
            printf("Consumer: Removed 1 item. Current shelf count: %d\n", shelf_count - 1);
            sleep(1);  // Simulate time taken to remove an item
        } else {
            printf("Consumer: Shelf is empty.\n");
        }
    }

    // Close FIFO
    close(pipe_fd);
    printf("Consumer finished.\n");
    exit(EXIT_SUCCESS);
}
