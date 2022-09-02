#include "statusbar.h"
#include "navbuttons.h"
#include <iostream>

int main(){

    sf::RenderWindow gameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tic-Tac-Toe", sf::Style::Close);
    Board gameBoard;
    statusBar statusBar;
    navButtons navButtons;

    while(gameWindow.isOpen()){

        sf::Event currentEvent;
        while(gameWindow.pollEvent(currentEvent)){

            if(currentEvent.type == sf::Event::Closed)
                gameWindow.close();

            else if(currentEvent.type == sf::Event::MouseButtonPressed){
                gameBoard.makeMove(currentEvent.mouseButton.x, currentEvent.mouseButton.y);
                if(navButtons.retryButtonClicked(currentEvent.mouseButton.x, currentEvent.mouseButton.y)){
                    std::cout << "Retry" << '\n';
                    gameBoard.reset();
                }
                if(navButtons.mainMenuButtonClicked(currentEvent.mouseButton.x, currentEvent.mouseButton.y))
                    std::cout << "Main Menu" << '\n';
            }

        }

        gameWindow.clear(sf::Color::White);

        gameBoard.draw(gameWindow);
        statusBar.draw(gameWindow, gameBoard.getCurrentPlayer(), gameBoard.getCurrentGameStatus());
        navButtons.draw(gameWindow);

        gameWindow.display();

    }

    return 0;
}