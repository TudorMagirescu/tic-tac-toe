#include <SFML/Graphics.hpp>
#include "constants.h"

int main(){

    sf::RenderWindow gameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tic-Tac-Toe", sf::Style::Close);

    while(gameWindow.isOpen()){

        sf::Event currentEvent;
        while(gameWindow.pollEvent(currentEvent)){

            if(currentEvent.type == sf::Event::Closed)
                gameWindow.close();

            else if(currentEvent.type == sf::Event::MouseButtonPressed){
                //do stuff
            }

        }

    }

    return 0;
}