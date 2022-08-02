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

void gameWindow :: drawRectangle(float width, float height, float position_x, float position_y){
    //draws a rectangle of dimensions (width, height) 
    //that has its upper left corner at position (position_x, position_y)
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(sf::Vector2f(position_x, position_y));
    rectangle.setFillColor(sf::Color::Black);
    window.draw(rectangle);
}

void gameWindow :: display(){
    window.display();
}

void gameWindow :: drawGameBoard(){   
    //draw the tic-tac-toe grid

    //draw the vertical lines
    for(int lineIndex=0; lineIndex<4; lineIndex++){
        
        //each line has a width of 3 and a height of 3/4 of the screen
        float width = 3;
        float height = 3 * BOARD_HEIGHT / 4;

        //vertical lines will be placed at 1/8, 3/8, 5/8 and 7/8 of the screen
        float position_x = BOARD_WIDTH / 8 + lineIndex * BOARD_WIDTH / 4;
        float position_y = BOARD_HEIGHT / 8;

        drawRectangle(width, height, position_x, position_y);
    }

    //draw the horizontal lines
    for(int lineIndex=0; lineIndex<4; lineIndex++){

        //each line has a height of 3 and a width of 3/4 of the screen
        float width = 3 * BOARD_HEIGHT / 4;
        float height = 3;

        //horizontal lines will be placed at 1/8, 3/8, 5/8, 7/8 of the screen
        float position_x = BOARD_WIDTH / 8;
        float position_y = BOARD_HEIGHT / 8 + lineIndex * BOARD_HEIGHT / 4;

        drawRectangle(width, height, position_x, position_y);
    }

}

void gameWindow :: drawAll(sf::Color backgroundColor){
    //the only public function of class gameWindow
    //will take care of all of the drawing

    clearWindow(backgroundColor);
    drawGameBoard();
    display();
}