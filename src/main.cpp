#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
#include "gamewindow.h"

int main(){

    gameWindow gameWindow;
    while(gameWindow.isOpen()){
        gameWindow.handleEvents();
    }

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

    return 0;
}