#include "game.h"

void Game::changePlayer(){
    if(currentPlayer == Player::X)
        currentPlayer = Player::Zero;
    else
        currentPlayer = Player::X;
}

Game::Game(){
    //initialise the currentPlayer to Player::X at the beginning of the game
    currentPlayer = Player::X;
}

void Game::newTurn(){
    //current turn of the game

    //we start by printing the board
    gameBoard.printBoard();

    //then the current player makes a move
    std::pair <int, int> move = {0, 0};

    //mark the move on the board
    gameBoard.update(move, currentPlayer);

    //change the current player to prepare for the next turn
    changePlayer();
}