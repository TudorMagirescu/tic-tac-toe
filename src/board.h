#include <utility>
#include "constants.h"

enum class Player{
    //Each board cell has one of the following states, depending on which player marked it.
    //X and Zero are the two players
    //NA means that the cell is unoccupied
    
    X,
    Zero,
    NA
};

class Board{

    private:
        
        Player board[3][3];
        std::pair <int, int> processMove(int mouse_x, int mouse_y);

    public:

        Board();
        void newTurn(int mouse_x, int mouse_y);

};