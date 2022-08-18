#include "graphics.h"

void Graphics :: drawLine(sf::RenderWindow &gameWindow, sf::Vector2f point0, sf::Vector2f point1, sf::Color lineColor){

    sf::VertexArray line(sf::Lines, 2);

    line[0].position = point0;
    line[1].position = point1;

    line[0].color = line[1].color = lineColor;

    gameWindow.draw(line);

}