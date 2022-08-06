#pragma once
#include <utility>
#include <string>

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
    public:
        Board();
        void update(std::pair <int, int> move, Player currentPlayer);
        Player getPlayerAtPosition(std::pair <int, int> move);
        Player getWinner();
        std::pair <std::string, int> getWinningLine();
};