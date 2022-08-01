#include <SFML/Graphics.hpp>

struct gameWindow{
    sf::RenderWindow window{sf::VideoMode{800, 800}, "Tic-Tac-Toe"};
    gameWindow();
};