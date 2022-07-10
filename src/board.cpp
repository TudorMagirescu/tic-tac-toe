#include "board.h"

Board::Board(){
    //Initialise each of the board's cells with the Player::NA type
    for(int row=0; row<3; row++)
        for(int col=0; col<3; col++)
            board[row][col] = Player::NA;
}