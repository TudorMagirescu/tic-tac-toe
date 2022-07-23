#include "board.h"

class Game{
    private:
        Board gameBoard;
        Player currentPlayer;
        Player winner;
        int turn;
        void changePlayer();
        std::pair <int, int> readMove();
    public:
        Game();
        void newTurn();
        Player getWinner();
        int getTurn();
};