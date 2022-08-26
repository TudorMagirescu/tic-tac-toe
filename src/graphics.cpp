#include "graphics.h"

void Graphics :: drawSpriteFromFileInCell(sf::RenderWindow &gameWindow, sf::Vector2f position, std::string filename){

    sf::Texture texture;

    texture.loadFromFile(filename);

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(position);

    gameWindow.draw(sprite);

}