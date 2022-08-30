#include "graphics.h"
#include "board.h"

class statusBar{

    private:

        std::string displayedMessage;
        int characterSize;
        sf::Font font;
        sf::Color color;

        void updateStatusBar(Player currentPlayer, gameStatus currentGameStatus);

    public:

        statusBar();

        void draw(sf::RenderWindow &gameWindow, Player currentPlayer, gameStatus currentGameStatus);

};