#include "board.h"
#include <iostream> //remove after debug

Board :: Board() {

    for (int row = 0; row < 3; row++)
        for (int column = 0; column < 3; column++) {
            board[row][column] = Player::NA;
        }

}

std::pair <int, int> Board :: processMove(int mouse_x, int mouse_y) {

    //the function returns {-1, -1} if the move is invalid
    //otherwise it returns the cell which is marked by the current player

    bool insideBoard = true;
    int row, column;

    //get the column
    if(mouse_x < BOARD_WIDTH / 8 || mouse_x > 7 * BOARD_WIDTH / 8) {
        //the move is outside the board
        return {-1, -1};
    }
    column = (mouse_x - BOARD_WIDTH / 8) / (BOARD_WIDTH / 4);

    //get the row
    if(mouse_y < BOARD_HEIGHT / 8 || mouse_y > 7 * BOARD_HEIGHT / 8) {
        //the move is outside the board
        return {-1, -1};
    }
    row = (mouse_y - BOARD_HEIGHT / 8) / (BOARD_HEIGHT / 4);

    //if the cell is occupied the move is also invalid
    if(board[row][column] != Player::NA)
        return {-1, -1};

    return {row, column};


}

void Board :: newTurn(int mouse_x, int mouse_y) {

    std::pair <int, int> cell = processMove(mouse_x, mouse_y);

    std::cout << cell.first << ' ' << cell.second << '\n';

}