#include "statusbar.h"

statusBar :: statusBar(){

    displayedMessage = "Hello world!";
    characterSize = 30;
    font.loadFromFile("fonts/arial.ttf");
    color = sf::Color::Black;

}

void statusBar :: draw(sf::RenderWindow &gameWindow){

    //local variables for debugging only
    sf::Color color = sf::Color::Black;
    sf::Vector2f position;
    position.x = Graphics :: getPositionToCenterText(font, displayedMessage, characterSize);

    Graphics :: drawText(gameWindow, font, displayedMessage, color, characterSize, position);

}