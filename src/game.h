#include "board.h"
#include <utility>

class Game{
    private:
        Board gameBoard;
        Player currentPlayer;
    public:
        Game();
        void currentTurn();
};