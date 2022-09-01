#include "graphics.h"

class Button {

    private:

        std::string filename;
        sf::Vector2f position;
        sf::Vector2f size;

    public:

        Button(sf::Vector2f size, std::string filename);

        void setPosition(sf::Vector2f position);
        bool isClicked(float mouse_x, float mouse_y);

        void draw(sf::RenderWindow &gameWindow);


};