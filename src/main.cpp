#include <iostream>
#include "game.h"
#include "gamewindow.h"

int main(){

    gameWindow gameWindow;
    Game game;

    while(gameWindow.isOpen()){

        //check if the game ended
        if(game.getWinner() != Player::NA || game.getTurn() == 9){
            std::cout << "Game ended!" << '\n';
            //Work is required here
        }

        //process the current events
        gameWindow.handleEvents();

        //display the current state of the board
        gameWindow.drawAll(sf::Color::White);

        //check if there is any new move
        if(gameWindow.getMouseClicked() == true){
            std::cout << "The user clicked the mouse!" << '\n';
            game.newTurn(gameWindow.getMouse_x(), gameWindow.getMouse_y());
        }

    }
    /*

    Game game;

    while(game.getWinner() == Player::NA && game.getTurn() < 9){
        game.newTurn();
    }

    if(game.getTurn() == 9){
        //the game ended in a draw
        std::cout << "The game ended in a draw!" << '\n';
    }

    else{
        if(game.getWinner() == Player::X)
            std::cout << "X wins!" << '\n';
        else
            std::cout << "Zero wins!" << '\n';
    }

    */

    return 0;
}