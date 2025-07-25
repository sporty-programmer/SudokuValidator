#include "sudoku.h"


bool solve(char board[9][9]) {

    BoardMem rows = {0, 0};
    BoardMem cols = {0, 0};
    BoardMem boxes = {0, 0};

    if (!scanBoard(board, &rows, &cols, &boxes)) return false;

    return true;
}


bool scanBoard(char board[9][9], BoardMem* rows, BoardMem* cols, BoardMem* boxes) {

    for (int i = 0; i < 9; ++i) { // row
        for (int j = 0; j < 9; ++j) { // col

            if (board[i][j] == '.') continue; // no entry

            const int num = board[i][j] - '1'; // index from 0 to 8
            const int boxIndex = (i / 3) * 3 + (j / 3); // index for boxes from 0 to 8 (1. top -> bottom; 2. right -> left)

            // num already exists in its row, col or box
            if (getBoardMem(rows, i * 9 + num)
                || getBoardMem(cols, j * 9 + num)
                || getBoardMem(boxes, boxIndex * 9 + num)) return false;

            // add num to its current row, col and box
            setBoardMem(rows, i * 9 + num);
            setBoardMem(cols, j * 9 + num);
            setBoardMem(boxes, boxIndex * 9 + num);
        }
    }

    return true;
}


bool getBoardMem(const BoardMem* boardMem, const uint8_t index) {
    if (index > 80) return NULL;
    if (index < 64) return (boardMem->low >> index) & 1;
    return (boardMem->high >> (index - 64)) & 1;
}

void setBoardMem(BoardMem* boardMem, const uint8_t index) {
    if (index > 80) return;
    if (index < 64) boardMem->low |= ((uint64_t) 1 << index);
    else boardMem->high |= ((uint16_t) 1 << (index - 64));
}