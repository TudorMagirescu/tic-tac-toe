#include "cell.h"
#include "graphics.h"
#include <utility>

enum class gameStatus {
    //the status of the game
    
    ONGOING,
    X_WINS,
    ZERO_WINS,
    DRAW

};

class Board{

    private:
        
        Cell board[3][3];
        Player currentPlayer;
        gameStatus currentGameStatus;

        sf::Clock blinkingClock;

        std::pair <int, int> processMove(int mouse_x, int mouse_y);
        void checkForWin();

        void handleBlinking(sf::RenderWindow &gameWindow, int row, int column);

    public:

        Board();
        void makeMove(int mouse_x, int mouse_y);

        void draw(sf::RenderWindow &gameWindow);

};