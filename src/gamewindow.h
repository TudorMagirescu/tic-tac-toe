#include <SFML/Graphics.hpp>

class gameWindow{
    private:

        const unsigned int BOARD_WIDTH = 800;
        const unsigned int BOARD_HEIGHT = 800;
        sf::RenderWindow window{sf::VideoMode{BOARD_WIDTH, BOARD_HEIGHT}, "Tic-Tac-Toe"};
        bool mouseClicked;

        void clearWindow(sf::Color color);
        void drawRectangle(float width, float height, float position_x, float position_y);
        void display();

        void drawGameBoard();

    public:

        bool isOpen();
        void handleEvents();
        bool getMouseClicked();
        
        void drawAll(sf::Color backgroundColor);
};