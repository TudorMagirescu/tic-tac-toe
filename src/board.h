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

        sf::Vector2f getPositionFromCellIndex(int row, int column);

        void handleBlinking(sf::RenderWindow &gameWindow, int row, int column);

    public:

        Board();
        void makeMove(int mouse_x, int mouse_y);

        Player getCurrentPlayer();
        gameStatus getCurrentGameStatus();

        void reset();

        void draw(sf::RenderWindow &gameWindow);

};