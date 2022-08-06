#include "board.h"
#include <iostream>

Board::Board(){
    //Initialise each of the board's cells with the Player::NA type
    for(int row=0; row<3; row++)
        for(int col=0; col<3; col++)
            board[row][col] = Player::NA;
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
    //It returns Player::NA in case the game is not won by any player

    std::pair <std::string, int> winningLine = getWinningLine();

    if(winningLine.first == "NA")
        return Player::NA;

    if(winningLine.first == "row")
        return board[winningLine.second][0];

    if(winningLine.first == "column")
        return board[0][winningLine.second];

    //the winning line is a diagonal

    if(winningLine.second == 0){
        //main diagonal
        return board[0][0];
    }

    //secondary diagonal
    return board[0][2];
    
}

std::pair <std::string, int> Board::getWinningLine(){
    //the function returns the winning line in case there exists one
    //the function returns (row/column/diagonal/NA, index number)
    //in case the first returned variable is "diagonal": 0 means the main diagonal and 1 the secondary diagonal
    //in case the first returned variable is "NA": -1 will be the index

    //check if there is any row completed by a player
    for(int row=0; row<3; row++){
        //check if the current row has all 3 cells occupied by the same player
        if(board[row][0] == board[row][1] && board[row][1] == board[row][2]){
            if(board[row][0] != Player::NA)
                return std::make_pair("row", row);
        }
    }

    //check if there is any column completed by a player
    for(int column=0; column<3; column++){
        //check if the current column has all 3 cells occupied by the same player
        if(board[0][column] == board[1][column] && board[1][column] == board[2][column]){
            if(board[0][column] != Player::NA)
                return std::make_pair("column", column);
        }
    }

    //check if the main diagonal is completed by a player
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != Player::NA)
        return std::make_pair("diagonal", 0);

    //check if the secondary diagonal is completed by a player
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != Player::NA)
        return std::make_pair("diagonal", 1);

    return std::make_pair("NA", -1);

}