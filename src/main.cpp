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
            gameWindow.close();
        }

        //process the current events
        gameWindow.handleEvents();

        //display the current state of the board
        gameWindow.drawCurrentFrame(sf::Color::White, game.getGameBoard());

        //check if there is any new move
        if(gameWindow.getMouseClicked() == true)
            game.newTurn(gameWindow.getMouse_x(), gameWindow.getMouse_y());

    }

    return 0;
}