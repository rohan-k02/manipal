/* Q1.  Process A wants to send a number to Process B. Once received, Process B has to check whether the number is
palindrome or not. Write a C program to implement this interprocess communication using a message queue. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 512

struct my_msg_st {
    long int my_msg_type;
    char some_text[MAX_TEXT];
};

int main() {
    struct my_msg_st some_data;
    int msgid;
    char buffer[BUFSIZ];
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if (msgid == -1) {
        fprintf(stderr, "msgget failed with error: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    printf("Enter a number: ");
    fgets(buffer, BUFSIZ, stdin);
    some_data.my_msg_type = 1;
    strcpy(some_data.some_text, buffer);

    if (msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0) == -1) {
        fprintf(stderr, "msgsnd failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Number sent to Process B: %s", buffer);

    exit(EXIT_SUCCESS);
}
