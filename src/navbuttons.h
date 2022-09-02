#include "button.h"

class navButtons{

    private:

        sf::Vector2f buttonSize{200, 70};
        Button retryButton{buttonSize, "img/RetryButton.png"}; 
        Button mainMenuButton{buttonSize, "img/RetryButton.png"};

    public:

        navButtons();

        void draw(sf::RenderWindow &gameWindow);

        bool retryButtonClicked(float mouse_x, float mouse_y);
        bool mainMenuButtonClicked(float mouse_x, float mouse_y);

};