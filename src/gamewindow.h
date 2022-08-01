#include <SFML/Graphics.hpp>

struct gameWindow{
    private:
        sf::RenderWindow window{sf::VideoMode{800, 800}, "Tic-Tac-Toe"};
        bool mouseClicked;
    public:
        bool isOpen();
        void handleEvents();
};