#include "board.h"

class Game{
    private:
        Board gameBoard;
        Player currentPlayer;
        void changePlayer();
    public:
        Game();
        void newTurn();
};