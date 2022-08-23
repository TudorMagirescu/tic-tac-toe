#include "graphics.h"

void Graphics :: drawLine(sf::RenderWindow &gameWindow, sf::Vector2f point0, sf::Vector2f point1, sf::Color lineColor){

    sf::VertexArray line(sf::Lines, 2);

    line[0].position = point0;
    line[1].position = point1;

    line[0].color = line[1].color = lineColor;

    gameWindow.draw(line);

}

void Graphics :: drawX(sf::RenderWindow &gameWindow, int row, int column, sf::Color xColor) {

    //draws an X at position (row, column)
    //use the PADDING variable to indicate the white space between the X and the borders of the cell

    //upper left point
    sf::Vector2f line0_point0;
    line0_point0.x = BOARD_WIDTH / 8 + column * BOARD_WIDTH / 4 + X_PADDING;
    line0_point0.y = BOARD_HEIGHT / 8 + row * BOARD_HEIGHT / 4 + X_PADDING;

    //lower right point
    sf::Vector2f line0_point1;
    line0_point1.x = line0_point0.x + BOARD_WIDTH / 4 - 2 * X_PADDING;
    line0_point1.y = line0_point0.y + BOARD_HEIGHT / 4 - 2 * X_PADDING;

    drawLine(gameWindow, line0_point0, line0_point1, xColor);

    //upper right point
    sf::Vector2f line1_point0;
    line1_point0.x = line0_point1.x;
    line1_point0.y = line0_point0.y;

    //lower right point
    sf::Vector2f line1_point1;
    line1_point1.x = line0_point0.x;
    line1_point1.y = line0_point1.y;

    drawLine(gameWindow, line1_point0, line1_point1, xColor);

}

void Graphics :: drawO(sf::RenderWindow &gameWindow, int row, int column, sf::Color oColor){
    
    //draws an O at position (row, column)
    //use the PADDING variable to indicate the white space between the ZERO and the borders of the cell

    //the position will be the upper left corner of the square in which the circle is inscribed
    float position_x = BOARD_WIDTH / 8 + column * BOARD_WIDTH / 4 + ZERO_PADDING;
    float position_y = BOARD_HEIGHT / 8 + row * BOARD_HEIGHT / 4 + ZERO_PADDING;

    float radius = (BOARD_WIDTH / 4 - 2 * ZERO_PADDING) / 2;

    sf::CircleShape zero(radius);
    zero.setPosition(sf::Vector2f(position_x, position_y));
    zero.setOutlineColor(oColor);
    zero.setOutlineThickness(1);

    gameWindow.draw(zero);
}