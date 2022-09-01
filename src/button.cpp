#include "button.h"

Button :: Button(sf::Vector2f size, std::string filename){

    this->size = size;
    this->filename = filename;
    position = sf::Vector2f(0, 0);

    hasText = false;

}

void Button :: setPosition(sf::Vector2f position){
    this->position = position;
}

bool Button :: isClicked(float mouse_x, float mouse_y){
    
    if(mouse_x >= position.x && mouse_x <= position.x + size.x - 1 && mouse_y >= position.y && mouse_y <= position.y + size.y - 1)
        return true;
    return false;
}

void Button :: setText(sf::Font font, std::string string, sf::Color color, int size){
    
    hasText = true;

    textFont = font;
    textString = string;
    textColor = color;
    textSize = size;

    textPosition.x = Graphics :: getPositionToCenterTextHorizontally(font, string, size, position.x, position.x + this->size.x - 1);
    textPosition.y = Graphics :: getPositionToCenterTextVertically(font, string, size, position.y, position.y + this->size.y - 1);

}

void Button :: draw(sf::RenderWindow &gameWindow){

    Graphics :: drawSpriteFromFile(gameWindow, position, filename);

    if(hasText)
        Graphics :: drawText(gameWindow, textFont, textString, textColor, textSize, textPosition);
    
}