#include "board.h"

Board :: Board() {

    currentPlayer = Player::X;

    currentGameStatus = gameStatus::ONGOING;

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
    if(board[row][column].player != Player::NA)
        return {-1, -1};

    return {row, column};


}

sf::Vector2f Board :: getPositionFromCellIndex(int row, int column){

    sf::Vector2f spritePosition;

    spritePosition.x = BOARD_WIDTH / 8 + column * BOARD_WIDTH / 4 - BORDER_SIZE * column;
    spritePosition.y = BOARD_HEIGHT / 8 + row * BOARD_HEIGHT / 4 - BORDER_SIZE * row;

    return spritePosition;

}

void Board :: checkForWin(){

    //check if there is any row completed by a player
    for(int row = 0; row < 3; row ++) {

        if(board[row][0].player == board[row][1].player && board[row][1].player == board[row][2].player){
            if(board[row][0].player != Player::NA){

                for(int column = 0; column < 3; column ++)
                    board[row][column].isBlinking = true;

                if(board[row][0].player == Player::X)
                    currentGameStatus = gameStatus::X_WINS;
                else
                    currentGameStatus = gameStatus::ZERO_WINS;

                return;

            }
        }

    }

    //check if there is any column completed by a player
    for(int column = 0; column < 3; column ++) {

        if(board[0][column].player == board[1][column].player && board[1][column].player == board[2][column].player){
            if(board[0][column].player != Player::NA){

                for(int row = 0; row < 3; row ++)
                    board[row][column].isBlinking = true;

                if(board[0][column].player == Player::X)
                    currentGameStatus = gameStatus::X_WINS;
                else
                    currentGameStatus = gameStatus::ZERO_WINS;

                return;

            }
        }

    }

    //check if the main diagonal is completed by any player
    if(board[0][0].player == board[1][1].player && board[1][1].player == board[2][2].player)
        if(board[0][0].player != Player::NA){

            for(int index = 0; index < 3; index ++)
                board[index][index].isBlinking = true;

            if(board[0][0].player == Player::X)
                currentGameStatus = gameStatus::X_WINS;
            else
                currentGameStatus = gameStatus::ZERO_WINS;

            return;    

        }

    //check if the secondary diagonal is completed by any player
    if(board[0][2].player == board[1][1].player && board[1][1].player == board[2][0].player)
        if(board[0][2].player != Player::NA){

            for(int index = 0; index < 3; index ++)
                board[index][2 - index].isBlinking = true;

            if(board[0][2].player == Player::X)
                currentGameStatus = gameStatus::X_WINS;
            else
                currentGameStatus = gameStatus::ZERO_WINS;

            return;    

        }

    //check for a draw
    for(int row = 0; row < 3; row ++)
        for(int column = 0; column < 3; column ++)
            if(board[row][column].player == Player::NA){
                //there can't be a draw since there is an unoccupied cell
                currentGameStatus = gameStatus::ONGOING;
                return;
            }

    currentGameStatus = gameStatus::DRAW;

}

void Board :: makeMove(int mouse_x, int mouse_y) {

    //check if the game ended 
    if(currentGameStatus != gameStatus::ONGOING)
        return;

    std::pair <int, int> cell = processMove(mouse_x, mouse_y);
    
    if(cell.first != -1){

        //the move is valid
        board[cell.first][cell.second].player = currentPlayer;

        //change player
        if(currentPlayer == Player::X)
            currentPlayer = Player::Zero;
        else
            currentPlayer = Player::X;

        checkForWin();

    }

}

void Board :: handleBlinking(sf::RenderWindow &gameWindow, int row, int column){

    //the cells which are part of the winning line will blink every second after the game has ended
    float blinkingTimeElapsed = blinkingClock.getElapsedTime().asSeconds();

    if(blinkingTimeElapsed > 2.0f)
        blinkingClock.restart();

    else if(blinkingTimeElapsed < 1.0f){
        //the first second this cell will appear as marked
        std::string filename = "img/O.png";
        if(board[row][column].player == Player::X)
            filename = "img/X.png";

        Graphics :: drawSpriteFromFile(gameWindow, getPositionFromCellIndex(row, column), filename);
        
    }

    else{
        //the next second this cell will appear as unmarked
        Graphics :: drawSpriteFromFile(gameWindow, getPositionFromCellIndex(row, column), "img/EmptyCell.png");
    }

}

void Board :: draw(sf::RenderWindow &gameWindow){

    for (int row = 0; row < 3; row ++)
        for (int column = 0; column < 3; column ++){

            if(board[row][column].player == Player::NA)
                Graphics :: drawSpriteFromFile(gameWindow, getPositionFromCellIndex(row, column), "img/EmptyCell.png");
            
            else if(board[row][column].player == Player::Zero)
                Graphics :: drawSpriteFromFile(gameWindow, getPositionFromCellIndex(row, column), "img/O.png");
                
            else
                Graphics :: drawSpriteFromFile(gameWindow, getPositionFromCellIndex(row, column), "img/X.png");

            if(board[row][column].isBlinking)
                handleBlinking(gameWindow, row, column);

        }

}