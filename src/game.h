#include "board.h"

class Game{
    private:
        Board gameBoard;
        Player currentPlayer;
        void changePlayer();
        std::pair <int, int> readMove();
    public:
        Game();
        void newTurn();
};