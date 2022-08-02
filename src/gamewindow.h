#include <SFML/Graphics.hpp>
#include "constants.h"

class gameWindow{
    private:

        sf::RenderWindow window{sf::VideoMode{BOARD_WIDTH, BOARD_HEIGHT}, "Tic-Tac-Toe"};
        bool mouseClicked;
        int mouse_x;
        int mouse_y;

        void clearWindow(sf::Color color);
        void drawRectangle(float width, float height, float position_x, float position_y);
        void display();

        void drawGameBoard();

    public:

        bool isOpen();
        void close();
        void handleEvents();

        bool getMouseClicked();
        int getMouse_x();
        int getMouse_y();
        
        void drawAll(sf::Color backgroundColor);
};