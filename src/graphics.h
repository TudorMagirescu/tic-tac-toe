#include <SFML/Graphics.hpp>
#include "constants.h"
#include <string>

namespace Graphics {

    void drawSpriteFromFile(sf::RenderWindow &gameWindow, sf::Vector2f position, std::string filename);

    float getPositionToCenterTextHorizontally(sf::Font font, std::string string, int size);
    float getPositionToCenterTextVertically(sf::Font font, std::string string, int size, float top, float bottom);

    void drawText(sf::RenderWindow &gameWindow, sf::Font font, std::string string, sf::Color color, int size, sf::Vector2f position);

};