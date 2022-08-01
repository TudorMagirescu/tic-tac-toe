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
        }

    }
    
}

bool gameWindow :: getMouseClicked(){
    return mouseClicked;
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