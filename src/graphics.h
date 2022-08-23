#include <SFML/Graphics.hpp>
#include "constants.h"

namespace Graphics {

    void drawLine(sf::RenderWindow &gameWindow, sf::Vector2f point0, sf::Vector2f point1, sf::Color lineColor);

    void drawX(sf::RenderWindow &gameWindow, int row, int column, sf::Color xColor);

    void drawO(sf::RenderWindow &gameWindow, int row, int column, sf::Color xColor);

};