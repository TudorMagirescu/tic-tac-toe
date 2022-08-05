#include "board.h"
#include "constants.h"

enum class gameStatus{
    //the status of the game
    
    ONGOING,
    X_WINS,
    ZERO_WINS,
    DRAW

};

class Game{
    private:
        Board gameBoard;
        Player currentPlayer;
        gameStatus currentGameStatus;
        int turn;

        void changePlayer();
        std::pair <int, int> processMove(int mouse_x, int mouse_y);
        
    public:
        Game();

        Board getGameBoard();

        void newTurn(int mouse_x, int mouse_y);
    
        gameStatus getGameStatus();
};