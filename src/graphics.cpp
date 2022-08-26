#include "graphics.h"

void Graphics :: drawSpriteFromFileInCell(sf::RenderWindow &gameWindow, int row, int column, std::string filename){

    sf::Vector2f position;
    position.x = BOARD_WIDTH / 8 + column * BOARD_WIDTH / 4 - BORDER_SIZE * column;
    position.y = BOARD_HEIGHT / 8 + row * BOARD_HEIGHT / 4 - BORDER_SIZE * row;
    //the borders of adjacent sprites will overlap

    sf::Texture texture;

    texture.loadFromFile(filename);

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(position);

    gameWindow.draw(sprite);

}