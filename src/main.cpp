#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"

int main(){
    

    //Create a sfml window in order to test sfml
    //Draw and display a white circle on a black background
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        sf::CircleShape testCircle(200.f);
        testCircle.setFillColor(sf::Color::White);
        window.draw(testCircle);
        window.display();
    }

    
    Game game;

    while(game.getWinner() == Player::NA && game.getTurn() < 9){
        game.newTurn();
    }

    if(game.getTurn() == 9){
        //the game ended in a draw
        std::cout << "The game ended in a draw!" << '\n';
    }

    else{
        if(game.getWinner() == Player::X)
            std::cout << "X wins!" << '\n';
        else
            std::cout << "Zero wins!" << '\n';
    }

    return 0;
}