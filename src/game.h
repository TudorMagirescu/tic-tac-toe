#include "board.h"
#include "constants.h"

class Game{
    private:
        Board gameBoard;
        Player currentPlayer;
        Player winner;
        int turn;
        void changePlayer();
        std::pair <int, int> processMove(int mouse_x, int mouse_y);
    public:
        Game();

        Board getGameBoard();

        void newTurn(int mouse_x, int mouse_y);
        Player getWinner();
        int getTurn();
};