#include "statusbar.h"

statusBar :: statusBar(){

    characterSize = 30;
    font.loadFromFile("fonts/arial.ttf");
    color = sf::Color::Black;

}

void statusBar :: updateStatusBar(Player currentPlayer, gameStatus currentGameStatus){

    if(currentGameStatus == gameStatus::ONGOING){
        
        if(currentPlayer == Player::X){
            displayedMessage = "Current Player: X";
            color = sf::Color::Blue;
        }
        else{
            displayedMessage = "Current Player: O";
            color = sf::Color::Red;
        } 

    }
    else{

        if(currentGameStatus == gameStatus::X_WINS){
            displayedMessage = "X Wins!";
            color = sf::Color::Blue;
        }
            
        else if(currentGameStatus == gameStatus::ZERO_WINS){
            displayedMessage = "O Wins!";
            color = sf::Color::Red;
        }
            
        else{
            displayedMessage = "The game ended in a draw!";
            color = sf::Color::Black;
        }   

    }

}

void statusBar :: draw(sf::RenderWindow &gameWindow, Player currentPlayer, gameStatus currentGameStatus){

    updateStatusBar(currentPlayer, currentGameStatus);
    sf::Vector2f position;
    position.x = Graphics :: getPositionToCenterTextHorizontally(font, displayedMessage, characterSize);
    position.y = Graphics :: getPositionToCenterTextVertically(font, displayedMessage, characterSize, 0, BOARD_HEIGHT / 8);

    Graphics :: drawText(gameWindow, font, displayedMessage, color, characterSize, position);

}