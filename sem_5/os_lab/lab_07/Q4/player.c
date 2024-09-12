// player.c
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "shm_com.h"

void print_board(char board[]) {
    printf("\n");
    for (int i = 0; i < 9; i++) {
        printf(" %c ", board[i]);
        if ((i + 1) % 3 == 0) {
            printf("\n");
            if (i != 8) printf("---+---+---\n");
        } else {
            printf("|");
        }
    }
    printf("\n");
}

int check_winner(char board[]) {
    // Winning combinations
    int win_combinations[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (int i = 0; i < 8; i++) {
        if (board[win_combinations[i][0]] != ' ' &&
            board[win_combinations[i][0]] == board[win_combinations[i][1]] &&
            board[win_combinations[i][1]] == board[win_combinations[i][2]]) {
            return 1;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return 0; // Game is still ongoing
        }
    }

    return -1; // Draw
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <player_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int player = atoi(argv[1]);
    if (player != 1 && player != 2) {
        fprintf(stderr, "Player number must be 1 or 2\n");
        exit(EXIT_FAILURE);
    }

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

    shared_stuff = (struct shared_use_st *)shared_memory;

    if (player == 1) {
        // Initialize the board and flags if Player 1
        memset(shared_stuff->board, ' ', BOARD_SIZE);
        shared_stuff->turn = 0;  // Player 1's turn
        shared_stuff->game_over = 0;
    }

    while (!shared_stuff->game_over) {
        if (shared_stuff->turn == player - 1) {
            print_board(shared_stuff->board);

            int position;
            do {
                printf("Player %d, enter your move (1-9): ", player);
                scanf("%d", &position);
                position--;
            } while (position < 0 || position >= 9 || shared_stuff->board[position] != ' ');

            shared_stuff->board[position] = (player == 1) ? 'X' : 'O';

            if (check_winner(shared_stuff->board) == 1) {
                print_board(shared_stuff->board);
                printf("Player %d wins!\n", player);
                shared_stuff->game_over = 1;
            } else if (check_winner(shared_stuff->board) == -1) {
                print_board(shared_stuff->board);
                printf("The game is a draw!\n");
                shared_stuff->game_over = 1;
            } else {
                shared_stuff->turn = 1 - shared_stuff->turn; // Switch turns
            }
        } else {
            printf("Waiting for Player %d's move...\n", 3 - player);
            sleep(1);
        }
    }

    if (player == 1) {
        // Detach and remove shared memory after the game is over
        if (shmdt(shared_memory) == -1) {
            fprintf(stderr, "shmdt failed\n");
            exit(EXIT_FAILURE);
        }

        if (shmctl(shmid, IPC_RMID, 0) == -1) {
            fprintf(stderr, "shmctl(IPC_RMID) failed\n");
            exit(EXIT_FAILURE);
        }
    } else {
        // Detach shared memory for Player 2
        if (shmdt(shared_memory) == -1) {
            fprintf(stderr, "shmdt failed\n");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
