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