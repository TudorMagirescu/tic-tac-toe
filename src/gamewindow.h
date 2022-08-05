#include <SFML/Graphics.hpp>
#include "constants.h"

class gameWindow{
    private:

        sf::RenderWindow window{sf::VideoMode{BOARD_WIDTH, BOARD_HEIGHT}, "Tic-Tac-Toe"};
        bool mouseClicked;
        int mouse_x;
        int mouse_y;

        void clearWindow(sf::Color color);
        void drawLine(sf::Vector2f point0, sf::Vector2f point1, sf::Color lineColor);
        void drawX(int row, int column, sf::Color color);
        void drawO(int row, int column, sf::Color color);
        void drawGameBoard(sf::Color color);

        void display();


    public:

        bool isOpen();
        void close();
        void handleEvents();

        bool getMouseClicked();
        int getMouse_x();
        int getMouse_y();
        
        void drawAll(sf::Color backgroundColor);
    
};