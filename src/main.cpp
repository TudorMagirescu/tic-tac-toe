#include "statusbar.h"
#include "button.h"
#include <iostream>

int main(){

    sf::RenderWindow gameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tic-Tac-Toe", sf::Style::Close);
    Board gameBoard;
    statusBar statusBar;

    //debug
    float RetryX = (BOARD_WIDTH - 2 * 200) / 3;
    Button Retry(sf::Vector2f(200, 70), "img/RetryButton.png");
    Retry.setPosition(sf::Vector2f(RetryX, 740));
    sf::Font Arial;
    Arial.loadFromFile("fonts/arial.ttf");
    Retry.setText(Arial, "Retry", sf::Color::Black, 30);

    float MainMenuX = 200 + 2.0 * RetryX;
    Button MainMenu(sf::Vector2f(200, 70), "img/RetryButton.png");
    MainMenu.setPosition(sf::Vector2f(MainMenuX, 740));
    MainMenu.setText(Arial, "Main Menu", sf::Color::Black, 30);
    //end of debug

    while(gameWindow.isOpen()){

        sf::Event currentEvent;
        while(gameWindow.pollEvent(currentEvent)){

            if(currentEvent.type == sf::Event::Closed)
                gameWindow.close();

            else if(currentEvent.type == sf::Event::MouseButtonPressed){
                gameBoard.makeMove(currentEvent.mouseButton.x, currentEvent.mouseButton.y);

                //debug
                if(Retry.isClicked(currentEvent.mouseButton.x, currentEvent.mouseButton.y)){
                    gameBoard.reset();
                    std::cout << "Retry!" << '\n';
                }
                if(MainMenu.isClicked(currentEvent.mouseButton.x, currentEvent.mouseButton.y))
                    std::cout << "Main Menu!" << '\n';
                //end of debug
            }

        }

        gameWindow.clear(sf::Color::White);

        gameBoard.draw(gameWindow);
        statusBar.draw(gameWindow, gameBoard.getCurrentPlayer(), gameBoard.getCurrentGameStatus());

        //debug draw button
        
        Retry.draw(gameWindow);
        MainMenu.draw(gameWindow);
        
        //end of debug

        gameWindow.display();

    }

    return 0;
}