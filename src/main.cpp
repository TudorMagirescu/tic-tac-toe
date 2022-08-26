#include "board.h"

int main(){

    sf::RenderWindow gameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tic-Tac-Toe", sf::Style::Close);
    Board gameBoard;

    while(gameWindow.isOpen()){

        sf::Event currentEvent;
        while(gameWindow.pollEvent(currentEvent)){

            if(currentEvent.type == sf::Event::Closed)
                gameWindow.close();

            else if(currentEvent.type == sf::Event::MouseButtonPressed){
                gameBoard.makeMove(currentEvent.mouseButton.x, currentEvent.mouseButton.y);
            }

        }

        gameWindow.clear(sf::Color::White);

        gameBoard.draw(gameWindow);

        gameWindow.display();

    }

    return 0;
}