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
    //initialise the winner to Player::NA
    winner = Player::NA;
}

std::pair <int, int> Game::readMove(){
    //read the current player's move from the input
    //the function checks for the move to be valid
    //in case the move is invalid, the player is asked to input another move
    bool playedValidMove = false;
    int row, column;

    while(playedValidMove == false){
        //pretend the current move is valid
        playedValidMove = true;

        //read the user input
        std::cin >> row >> column;

        if(row < 0 || row > 2){
            //the row is invalid
            playedValidMove = false;
        }

        else if(column < 0 || column > 2){
            //the column is invalid
            playedValidMove = false;
        }

        else if(gameBoard.getPlayerAtPosition(std::make_pair(row, column)) != Player::NA){
            //the cell is already occupied
            playedValidMove = false;
        }

        if(playedValidMove == false){
            std::cout << "The move is invalid. Please input another move!" << '\n';
        }
    }

    return std::make_pair(row, column);
}

void Game::newTurn(){
    //current turn of the game

    //we start by printing the board
    gameBoard.printBoard();

    //then the current player makes a move
    std::pair <int, int> move = readMove();

    //mark the move on the board
    gameBoard.update(move, currentPlayer);

    //check if there is a winner of the game
    //winner = Player::NA in case the game is ongoing
    Player winner = gameBoard.getWinner();

    if(winner != Player::NA){
        this->winner = winner;
        gameBoard.printBoard();
    }

    //change the current player to prepare for the next turn
    changePlayer();
}

Player Game::getWinner(){
    return this->winner;
}