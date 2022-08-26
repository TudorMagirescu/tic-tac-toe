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

        //debug the draw text function
        sf::Font font;
        font.loadFromFile("fonts/arial.ttf");
        Graphics :: drawText(gameWindow, font, "Hello world!", sf::Color::Black, 30, sf::Vector2f(0, 0));
        //end of debug

        gameWindow.display();

    }

    return 0;
}