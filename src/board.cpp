#include "board.h"

Board :: Board() {

    for (int row = 0; row < 3; row++)
        for (int column = 0; column < 3; column++) {
            board[row][column] = Player::NA;
        }

    currentPlayer = Player::X;

}

std::pair <int, int> Board :: processMove(int mouse_x, int mouse_y) {

    //the function returns {-1, -1} if the move is invalid
    //otherwise it returns the cell which is marked by the current player

    bool insideBoard = true;
    int row, column;

    //get the column
    if(mouse_x < BOARD_WIDTH / 8 || mouse_x > 7 * BOARD_WIDTH / 8) {
        //the move is outside the board
        return {-1, -1};
    }
    column = (mouse_x - BOARD_WIDTH / 8) / (BOARD_WIDTH / 4);

    //get the row
    if(mouse_y < BOARD_HEIGHT / 8 || mouse_y > 7 * BOARD_HEIGHT / 8) {
        //the move is outside the board
        return {-1, -1};
    }
    row = (mouse_y - BOARD_HEIGHT / 8) / (BOARD_HEIGHT / 4);

    //if the cell is occupied the move is also invalid
    if(board[row][column] != Player::NA)
        return {-1, -1};

    return {row, column};


}

void Board :: makeMove(int mouse_x, int mouse_y) {

    std::pair <int, int> cell = processMove(mouse_x, mouse_y);
    
    if(cell.first != -1){

        //the move is valid
        board[cell.first][cell.second] = currentPlayer;

    }

    //change player
    if(currentPlayer == Player::X)
        currentPlayer = Player::Zero;
    else
        currentPlayer = Player::X;

}

void Board :: drawBoardGrid(sf::RenderWindow &gameWindow){

    //draw the tic-tac-toe grid

    //draw the vertical lines
    for(int lineIndex=0; lineIndex<4; lineIndex++){

        //vertical lines will be placed at 1/8, 3/8, 5/8 and 7/8 of the screen
        sf::Vector2f point0;
        point0.x = BOARD_WIDTH / 8 + lineIndex * BOARD_WIDTH / 4;
        point0.y = BOARD_HEIGHT / 8;

        sf::Vector2f point1;
        point1.x = point0.x;
        point1.y = 7 * BOARD_HEIGHT / 8;

        Graphics::drawLine(gameWindow, point0, point1, sf::Color::Black);
    }

    //draw the horizontal lines
    for(int lineIndex=0; lineIndex<4; lineIndex++){

        //horizontal lines will be placed at 1/8, 3/8, 5/8 and 7/8 of the screen
        sf::Vector2f point0;
        point0.x = BOARD_WIDTH / 8;
        point0.y = BOARD_HEIGHT / 8 + lineIndex * BOARD_HEIGHT / 4;

        sf::Vector2f point1;
        point1.x = 7 * BOARD_WIDTH / 8;
        point1.y = point0.y;

        Graphics::drawLine(gameWindow, point0, point1, sf::Color::Black);
    }

}

void Board :: drawGameBoard(sf::RenderWindow &gameWindow){

    drawBoardGrid(gameWindow);

    for (int row = 0; row < 3; row++)
        for (int column=0; column < 3; column++) {
            if(board[row][column] == Player::X)
                Graphics :: drawX(gameWindow, row, column, sf::Color::Blue);
            else if(board[row][column] == Player::Zero)
                Graphics :: drawO(gameWindow, row, column, sf::Color::Red);
        }

}