#include "graphics.h"

void Graphics :: drawSpriteFromFile(sf::RenderWindow &gameWindow, sf::Vector2f position, std::string filename){

    sf::Texture texture;

    texture.loadFromFile(filename);

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(position);

    gameWindow.draw(sprite);

}

float Graphics :: getPositionToCenterTextVertically(sf::Font font, std::string string, int size, float top, float bottom){

    sf::Text text;

    text.setFont(font);
    text.setString(string);
    text.setCharacterSize(size);

    //get the height of the rectangle surrounding the text
    sf::FloatRect surroundingRect = text.getLocalBounds();
    float height = surroundingRect.height;

    return top + (bottom - top + 1.0 - height) / 2.0;

}

float Graphics :: getPositionToCenterTextHorizontally(sf::Font font, std::string string, int size, float left, float right){

    sf::Text text;

    text.setFont(font);
    text.setString(string);
    text.setCharacterSize(size);

    //get the width of the rectangle surrounding the text
    sf::FloatRect surroundingRect = text.getLocalBounds();
    float width = surroundingRect.width;

    return left + (right - left + 1.0 - width) / 2.0;

}

void Graphics :: drawText(sf::RenderWindow &gameWindow, sf::Font font, std::string string, sf::Color color, int size, sf::Vector2f position){

    sf::Text text;

    text.setFont(font);
    text.setString(string);
    text.setFillColor(color);
    text.setCharacterSize(size);

    //before setting the position, set the origin to the top left corner of the rectangle surrounding the text
    sf::FloatRect surroundingRect = text.getLocalBounds();
    text.setOrigin(sf::Vector2f(surroundingRect.left, surroundingRect.top));

    text.setPosition(position);

    gameWindow.draw(text);

}