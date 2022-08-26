#include "graphics.h"

class statusBar{

    private:

        std::string displayedMessage;
        int characterSize;
        sf::Font font;
        sf::Color color;

    public:

        statusBar();

        void draw(sf::RenderWindow &gameWindow);

};