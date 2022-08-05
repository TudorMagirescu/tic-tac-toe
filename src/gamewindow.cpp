#include "gamewindow.h"

bool gameWindow :: isOpen(){
    return window.isOpen();
}

void gameWindow :: handleEvents(){

    //set the mouseClicked variable to false
    //the user click will determine if another move is made
    mouseClicked = false;

    //this function will deal with the events
    sf::Event currentEvent;
    while(window.pollEvent(currentEvent)){
        
        //check if the user closes the window
        if(currentEvent.type == sf::Event::Closed){
            window.close();
        }

        //check if the user clicks
        if(currentEvent.type == sf::Event::MouseButtonPressed){
            mouseClicked = true;
            mouse_x = currentEvent.mouseButton.x;
            mouse_y = currentEvent.mouseButton.y;
        }

    }
    
}

void gameWindow :: close(){
    window.close();
}

bool gameWindow :: getMouseClicked(){
    return mouseClicked;
}

int gameWindow :: getMouse_x(){
    return mouse_x;
}

int gameWindow :: getMouse_y(){
    return mouse_y;
}

void gameWindow :: clearWindow(sf::Color color){
    window.clear(color);
}

void gameWindow :: drawLine(sf::Vector2f point0, sf::Vector2f point1, sf::Color lineColor){
    //draws a line from point0 to point1
    //its color will be lineColor
    sf::VertexArray line(sf::Lines, 2);

    line[0].position = point0;
    line[1].position = point1;

    line[0].color = line[1].color = lineColor;

    window.draw(line);
}

void gameWindow :: display(){
    window.display();
}

void gameWindow :: drawGameBoard(sf::Color color){ 
    //draw the tic-tac-toe grid

    //draw the vertical lines
    for(int lineIndex=0; lineIndex<4; lineIndex++){

        //vertical lines will be placed at 1/8, 3/8, 5/8 and 7/8 of the screen
        float point0_x = BOARD_WIDTH / 8 + lineIndex * BOARD_WIDTH / 4;
        float point0_y = BOARD_HEIGHT / 8;
        sf::Vector2f point0(point0_x, point0_y);

        float point1_x = point0_x;
        float point1_y = 7 * BOARD_HEIGHT / 8;
        sf::Vector2f point1(point1_x, point1_y);

        drawLine(point0, point1, color);
    }

    //draw the horizontal lines
    for(int lineIndex=0; lineIndex<4; lineIndex++){

        //horizontal lines will be placed at 1/8, 3/8, 5/8 and 7/8 of the screen
        float point0_x = BOARD_WIDTH / 8;
        float point0_y = BOARD_HEIGHT / 8 + lineIndex * BOARD_HEIGHT / 4;
        sf::Vector2f point0(point0_x, point0_y);

        float point1_x = 7 * BOARD_WIDTH / 8;
        float point1_y = point0_y;
        sf::Vector2f point1(point1_x, point1_y);

        drawLine(point0, point1, color);
    }
}

void gameWindow :: drawX(int row, int column, sf::Color color){

    //draws an X at position (row, column)
    //use the PADDING variable to indicate the white space between the X and the borders of the cell

    //upper left point
    float line0_point0_x = BOARD_WIDTH / 8 + column * BOARD_WIDTH / 4 + X_PADDING;
    float line0_point0_y = BOARD_HEIGHT / 8 + row * BOARD_HEIGHT / 4 + X_PADDING;
    sf::Vector2f line0_point0(line0_point0_x, line0_point0_y);

    //lower right point
    float line0_point1_x = line0_point0_x + BOARD_WIDTH / 4 - 2 * X_PADDING;
    float line0_point1_y = line0_point0_y + BOARD_HEIGHT / 4 - 2 * X_PADDING;
    sf::Vector2f line0_point1(line0_point1_x, line0_point1_y);

    drawLine(line0_point0, line0_point1, color);

    //upper right point
    float line1_point0_x = line0_point1_x;
    float line1_point0_y = line0_point0_y;
    sf::Vector2f line1_point0(line1_point0_x, line1_point0_y);

    //lower right point
    float line1_point1_x = line0_point0_x;
    float line1_point1_y = line0_point1_y;
    sf::Vector2f line1_point1(line1_point1_x, line1_point1_y);

    drawLine(line1_point0, line1_point1, color);

}

void gameWindow :: drawO(int row, int column, sf::Color color){
    //draws at O at position (row, column)

    //the position will be the upper left corner of the square in which the circle is inscribed
    float position_x = BOARD_WIDTH / 8 + column * BOARD_WIDTH / 4 + ZERO_PADDING;
    float position_y = BOARD_HEIGHT / 8 + row * BOARD_HEIGHT / 4 + ZERO_PADDING;

    float radius = (CELL_WIDTH - 2 * ZERO_PADDING) / 2;

    sf::CircleShape zero(radius);
    zero.setPosition(sf::Vector2f(position_x, position_y));
    zero.setOutlineColor(color);
    zero.setOutlineThickness(1);

    window.draw(zero);

}

void gameWindow :: drawCurrentFrame(sf::Color backgroundColor, Board gameBoard){
    //the only public function of class gameWindow
    //will take care of all of the drawing

    clearWindow(backgroundColor);
    drawGameBoard(sf::Color::Black);
    
    //draw the Xs and Os
    for(int row=0; row<3; row++)
        for(int column=0; column<3; column++){

            Player playerAtCurrentPosition = gameBoard.getPlayerAtPosition({row, column});

            if(playerAtCurrentPosition == Player::Zero)
                drawO(row, column, sf::Color::Red);

            else if(playerAtCurrentPosition == Player::X)
                drawX(row, column, sf::Color::Blue);
        }

    display();
}