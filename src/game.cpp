#include "game.h"
#include <iostream>

void Game::changePlayer(){
    if(currentPlayer == Player::X)
        currentPlayer = Player::Zero;
    else
        currentPlayer = Player::X;
}

Game::Game(){
    //initialise the currentPlayer to Player::X at the beginning of the game
    currentPlayer = Player::X;

    winner = Player::NA;
    turn = 0;
}

Board Game::getGameBoard(){
    return gameBoard;
}

std::pair <int, int> Game::processMove(int mouse_x, int mouse_y){
    
    //the function returns (-1, -1) if the move is invalid
    //otherwise it returns the coordinates of the move

    bool insideBoard = true;
    int row, column;

    //get the column
    if(mouse_x < BOARD_WIDTH / 8 || mouse_x > 7 * BOARD_WIDTH / 8){
        //the move is outside the board
        return {-1, -1};
    }
    column = (mouse_x - BOARD_WIDTH / 8) / (BOARD_WIDTH / 4);

    //get the row
    if(mouse_y < BOARD_HEIGHT / 8 || mouse_y > 7 * BOARD_HEIGHT / 8){
        //the move is outside the board
        return {-1, -1};
    }
    row = (mouse_y - BOARD_HEIGHT / 8) / (BOARD_HEIGHT / 4);

    //if the cell is occupied the move is also invalid
    if(gameBoard.getPlayerAtPosition({row, column}) != Player::NA)
        return {-1, -1};

    return {row, column};

}

void Game::newTurn(int mouse_x, int mouse_y){

    //then the current player makes a move
    std::pair <int, int> move = processMove(mouse_x, mouse_y);

    //check if the move is invalid
    if(move.first == -1 && move.second == -1)
        return;

    turn++;

    //mark the move on the board
    gameBoard.update(move, currentPlayer);

    //check if there is a winner of the game
    //winner = Player::NA in case the game is ongoing
    Player winner = gameBoard.getWinner();

    if(winner != Player::NA)
        this->winner = winner;

    //change the current player to prepare for the next turn
    changePlayer();
}

Player Game::getWinner(){
    return this->winner;
}

int Game::getTurn(){
    return this->turn;
}