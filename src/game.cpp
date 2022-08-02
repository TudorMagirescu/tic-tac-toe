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

std::pair <int, int> Game::readMove(){
    //read the current player's move from the input
    //the function checks for the move to be valid
    //in case the move is invalid, the player is asked to input another move
    bool playedValidMove = false;
    int row, column;

    //output the current player
    std::cout << "The current player is: ";
    if(currentPlayer == Player::X)
        std::cout << "X";
    else
        std::cout << "O";
    std::cout << '\n';

    while(playedValidMove == false){
        //pretend the current move is valid
        playedValidMove = true;

        //ask the user for the row
        std::cout << "Row (input a number from 0 to 2): ";
        
        //read the user input (row)
        std::cin >> row;

        if(row < 0 || row > 2){
            //the row is invalid
            playedValidMove = false;
        }

        //ask the user for the column
        std::cout << "Column (input a number from 0 to 2): ";

        //read the user input (column)
        std::cin >> column;

        if(column < 0 || column > 2){
            //the column is invalid
            playedValidMove = false;
        }

        if(gameBoard.getPlayerAtPosition(std::make_pair(row, column)) != Player::NA){
            //the cell is already occupied
            playedValidMove = false;
        }

        if(playedValidMove == false){
            std::cout << "The move is invalid. Please input another move!" << '\n';
        }
    }

    return std::make_pair(row, column);
}

void Game::newTurn(int mouse_x, int mouse_y){
    //current turn of the game
    turn++;

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

int Game::getTurn(){
    return this->turn;
}