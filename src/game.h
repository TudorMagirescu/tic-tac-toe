#include "board.h"

class Game{
    private:
        Board gameBoard;
        Player currentPlayer;
    public:
        Game();
        void printBoard();
};