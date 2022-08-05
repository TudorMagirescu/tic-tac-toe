#include <iostream>
#include "game.h"
#include "gamewindow.h"

int main(){

    gameWindow gameWindow;
    Game game;

    while(gameWindow.isOpen()){

        //process the current events
        gameWindow.handleEvents();

        //check if the game ended
        if(game.getGameStatus() != gameStatus::ONGOING){
            gameWindow.drawCurrentFrame(sf::Color::White, game.getGameBoard());
        }

        else{

            //display the current state of the board
            gameWindow.drawCurrentFrame(sf::Color::White, game.getGameBoard());

            //check if there is any new move
            if(gameWindow.getMouseClicked() == true)
                game.newTurn(gameWindow.getMouse_x(), gameWindow.getMouse_y());

        }


    }

    return 0;
}