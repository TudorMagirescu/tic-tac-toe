#include <utility>
#include "graphics.h"

enum class Player{
    //Each board cell has one of the following states, depending on which player marked it.
    //X and Zero are the two players
    //NA means that the cell is unoccupied
    
    X,
    Zero,
    NA
};

enum class gameStatus {
    //the status of the game
    
    ONGOING,
    X_WINS,
    ZERO_WINS,
    DRAW

};

enum class lineType {

    NA,
    ROW,
    COLUMN,
    DIAGONAL

};

class Board{

    private:
        
        Player board[3][3];
        Player currentPlayer;
        gameStatus currentGameStatus;

        std::pair <int, int> processMove(int mouse_x, int mouse_y);
        std::pair <lineType, int> getWinningLine();
        gameStatus updateGameStatus();

        void drawBoardGrid(sf::RenderWindow &gameWindow);

    public:

        Board();
        void makeMove(int mouse_x, int mouse_y);

        void drawGameBoard(sf::RenderWindow &gameWindow);

};