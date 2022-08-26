#include "graphics.h"

void Graphics :: drawSpriteFromFileInCell(sf::RenderWindow &gameWindow, int row, int column, std::string filename){

    sf::Vector2f position;
    position.x = BOARD_WIDTH / 8 + column * BOARD_WIDTH / 4;
    position.y = BOARD_HEIGHT / 8 + row * BOARD_HEIGHT / 4;

    sf::Texture texture;

    texture.loadFromFile(filename);

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(position);

    gameWindow.draw(sprite);

}