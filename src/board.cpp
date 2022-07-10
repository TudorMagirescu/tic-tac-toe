#include "board.h"
#include <iostream>

Board::Board(){
    //Initialise each of the board's cells with the Player::NA type
    for(int row=0; row<3; row++)
        for(int col=0; col<3; col++)
            board[row][col] = Player::NA;
}

void Board::printBoard(){
    //print the board
    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            if(board[row][col] == Player::NA)
                std::cout << "_" << ' ';
            else if(board[row][col] == Player::X)
                std::cout << "X" << ' ';
            else
                std::cout << "O" << ' ';
        }
        std::cout << '\n';
    }
}