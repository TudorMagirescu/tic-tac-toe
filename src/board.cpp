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

void Board::update(std::pair <int, int> move, Player currentPlayer){
    int row = move.first;
    int col = move.second;

    board[row][col] = currentPlayer;
}

Player Board::getPlayerAtPosition(std::pair <int, int> move){
    int row = move.first;
    int col = move.second;

    return board[row][col];
}

Player Board::getWinner(){
    //the function returns the winner of the game
    //It returns Player::X or Player::Zero in case there is a winner
    //It returns Player::NA in case the game is not finished

    //check if there is any row completed by a player
    for(int row=0; row<3; row++){
        //check if the current row has all 3 cells occupied by the same player
        if(board[row][0] == board[row][1] && board[row][1] == board[row][2]){
            if(board[row][0] != Player::NA)
                return board[row][0];
        }
    }

    //check if there is any column completed by a player
    for(int column=0; column<3; column++){
        //check if the current column has all 3 cells occupied by the same player
        if(board[0][column] == board[1][column] && board[1][column] == board[2][column]){
            if(board[0][column] != Player::NA)
                return board[0][column];
        }
    }

    //check if the main diagonal is completed by a player
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != Player::NA)
        return board[0][0];

    //check if the secondary diagonal is completed by a player
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != Player::NA)
        return board[0][2];

    return Player::NA;
}