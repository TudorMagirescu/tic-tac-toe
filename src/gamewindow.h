#include <SFML/Graphics.hpp>

struct gameWindow{
    private:
        sf::RenderWindow window{sf::VideoMode{800, 800}, "Tic-Tac-Toe"};
        bool mouseClicked;
    public:
        bool isOpen();
        void handleEvents();
        bool getMouseClicked();

        void clearWindow(sf::Color color);
        void drawRectangle(float width, float height, float position_x, float position_y);
        void display();
};