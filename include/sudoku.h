#ifndef SUDOKU_H
#define SUDOKU_H



#include <stdint.h>
#include <stdbool.h>


typedef struct {
    uint64_t low;
    uint32_t high;
} BoardMem;

bool getBoardMem(const BoardMem* boardMem, uint8_t index);
void setBoardMem(BoardMem* boardMem, uint8_t index);


bool solve(char board[9][9]);
bool scanBoard(char board[9][9], BoardMem* rows, BoardMem* cols, BoardMem* boxes);



#endif //SUDOKU_H
