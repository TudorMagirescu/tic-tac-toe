#include "graphics.h"

class Button {

    private:

        std::string filename;
        sf::Vector2f position;
        sf::Vector2f size;

        bool hasText; //the button may hold text
        sf::Font textFont;
        std::string textString;
        sf::Color textColor;
        int textSize;
        sf::Vector2f textPosition;

    public:

        Button(sf::Vector2f size, std::string filename);

        void setPosition(sf::Vector2f position);
        bool isClicked(float mouse_x, float mouse_y);

        void setText(sf::Font font, std::string string, sf::Color color, int size);

        void draw(sf::RenderWindow &gameWindow);


};