#include "game.h"

Game::Game(){
    //initialise the currentPlayer to Player::X at the beginning of the game
    currentPlayer = Player::X;
}

void Game::printBoard(){
    gameBoard.printBoard();
}