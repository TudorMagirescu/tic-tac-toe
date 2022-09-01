#include "button.h"
#include <iostream>

Button :: Button(sf::Vector2f size, std::string filename){

    this->size = size;
    this->filename = filename;
    position = sf::Vector2f(0, 0);

}

void Button :: setPosition(sf::Vector2f position){
    this->position = position;
}

bool Button :: isClicked(float mouse_x, float mouse_y){
    
    if(mouse_x >= position.x && mouse_x <= position.x + size.x - 1 && mouse_y >= position.y && mouse_y <= position.y + size.y - 1)
        return true;
    return false;
}

void Button :: draw(sf::RenderWindow &gameWindow){
    Graphics :: drawSpriteFromFile(gameWindow, position, filename);
}