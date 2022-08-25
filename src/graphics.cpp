#include "graphics.h"
#include <iostream>

void Graphics :: drawSpriteFromFileInCell(sf::RenderWindow &gameWindow, int row, int column, std::string filename){

    sf::Vector2f position;
    position.x = BOARD_WIDTH / 8 + column * BOARD_WIDTH / 4;
    position.y = BOARD_HEIGHT / 8 + row * BOARD_HEIGHT / 4;

    sf::Texture texture;

    if(texture.loadFromFile(filename) == false)
        std :: cerr << "The file you tried to draw the texture from does not exist!" << '\n';

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(position);

    gameWindow.draw(sprite);

}