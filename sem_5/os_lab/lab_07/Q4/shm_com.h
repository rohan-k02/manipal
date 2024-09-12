// shm_com.h
#ifndef SHM_COM_H
#define SHM_COM_H

#define BOARD_SIZE 9

struct shared_use_st {
    int turn;                 // 0 if it's Player 1's turn, 1 if it's Player 2's turn
    char board[BOARD_SIZE];   // Tic-Tac-Toe board
    int game_over;            // Flag to indicate if the game is over
};

#endif
