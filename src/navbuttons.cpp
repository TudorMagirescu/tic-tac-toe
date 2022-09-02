#include "navbuttons.h"

navButtons :: navButtons(){

    //load the font used for text
    sf::Font Arial;
    Arial.loadFromFile("fonts/arial.ttf");

    sf::Vector2f retryPosition;
    retryPosition.x = (WINDOW_WIDTH - 2 * buttonSize.x) / 3;
    retryPosition.y = (WINDOW_HEIGHT - 7 * BOARD_HEIGHT / 8 - buttonSize.y) / 2 + 7 * BOARD_HEIGHT / 8;
    retryButton.setPosition(retryPosition);
    retryButton.setText(Arial, "Retry", sf::Color::Black, 30);

    sf::Vector2f mainMenuPosition;
    mainMenuPosition.x = buttonSize.x + 2 * retryPosition.x;
    mainMenuPosition.y = retryPosition.y;
    mainMenuButton.setPosition(mainMenuPosition);
    mainMenuButton.setText(Arial, "Main Menu", sf::Color::Black, 30);

}

void navButtons :: draw(sf::RenderWindow &gameWindow){
    retryButton.draw(gameWindow);
    mainMenuButton.draw(gameWindow);
}

bool navButtons :: retryButtonClicked(float mouse_x, float mouse_y){
    return retryButton.isClicked(mouse_x, mouse_y);
}

bool navButtons :: mainMenuButtonClicked(float mouse_x, float mouse_y){
    return mainMenuButton.isClicked(mouse_x, mouse_y);
}