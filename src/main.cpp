#include <iostream>
#include "game.h"

int main(){
    
    Game game;

    while(game.getWinner() == Player::NA){
        game.newTurn();
    }

    return 0;
}