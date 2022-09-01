#include "statusbar.h"
#include <iostream>

int main(){

    sf::RenderWindow gameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tic-Tac-Toe", sf::Style::Close);
    Board gameBoard;
    statusBar statusBar;

    while(gameWindow.isOpen()){

        sf::Event currentEvent;
        while(gameWindow.pollEvent(currentEvent)){

            if(currentEvent.type == sf::Event::Closed)
                gameWindow.close();

            else if(currentEvent.type == sf::Event::MouseButtonPressed){
                gameBoard.makeMove(currentEvent.mouseButton.x, currentEvent.mouseButton.y);
                std::cout << currentEvent.mouseButton.x << ' ' << currentEvent.mouseButton.y << '\n';
            }

        }

        gameWindow.clear(sf::Color::White);

        gameBoard.draw(gameWindow);
        statusBar.draw(gameWindow, gameBoard.getCurrentPlayer(), gameBoard.getCurrentGameStatus());

        //debug draw button
        Graphics :: drawSpriteFromFile(gameWindow, sf::Vector2f(133, 740), "img/RetryButton.png");
        
        /*sf::RectangleShape rect1(sf::Vector2f(200, 70));
        rect1.setOutlineThickness(3);
        rect1.setPosition(sf::Vector2f(133, 740));
        rect1.setFillColor(sf::Color::White);
        rect1.setOutlineColor(sf::Color::Black);
        gameWindow.draw(rect1);*/

        Graphics :: drawSpriteFromFile(gameWindow, sf::Vector2f(466, 740), "img/RetryButton.png");

        /*sf::RectangleShape rect2(sf::Vector2f(200, 70));
        rect2.setOutlineThickness(3);
        rect2.setPosition(sf::Vector2f(466, 740));
        rect2.setFillColor(sf::Color::White);
        rect2.setOutlineColor(sf::Color::Black);
        gameWindow.draw(rect2);*/
        
        //end of debug

        gameWindow.display();

    }

    return 0;
}