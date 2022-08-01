#include <iostream>
#include "game.h"
#include "graphics.h"

int main(){

    gameWindow gameWindow;

    while(gameWindow.isOpen()){
        
        gameWindow.handleEvents();
        if(gameWindow.getMouseClicked() == true)
            std::cout << "The user clicked the mouse!" << '\n';

        gameWindow.clearWindow(sf::Color::White);
        Graphics::drawGameBoard(gameWindow);
        gameWindow.display();

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