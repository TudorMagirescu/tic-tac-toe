#include "board.h"

Board :: Board() {

    for (int row = 0; row < 3; row++)
        for (int column = 0; column < 3; column++) {
            board[row][column] = Player::NA;
        }

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
    if(board[row][column] != Player::NA)
        return {-1, -1};

    return {row, column};


}

std::pair <lineType, int> Board :: getWinningLine(){

    //the function returns {row/column/diagonal/NA, index}
    //in case the first returned variable is "diagonal": 0 means the main diagonal and 1 the secondary diagonal

    //check if there is any row completed by a player
    for(int row=0; row<3; row++) {

        if(board[row][0] == board[row][1] && board[row][1] == board[row][2]){
            if(board[row][0] != Player::NA)
                return std::make_pair(lineType::ROW, row);
        }

    }

    //check if there is any column completed by a player
    for(int column=0; column<3; column++){

        if(board[0][column] == board[1][column] && board[1][column] == board[2][column]){
            if(board[0][column] != Player::NA)
                return std::make_pair(lineType::COLUMN, column);
        }

    }

    //check if the main diagonal is completed by a player
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != Player::NA)
        return std::make_pair(lineType::DIAGONAL, 0);

    //check if the secondary diagonal is completed by a player
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != Player::NA)
        return std::make_pair(lineType::DIAGONAL, 1);

    return std::make_pair(lineType::NA, -1);

}

 gameStatus Board :: updateGameStatus(){

    std::pair <lineType, int> winningLine = getWinningLine();

    if(winningLine.first == lineType::ROW) {

        if(board[winningLine.second][0] == Player::X)
            return gameStatus::X_WINS;
        return gameStatus::ZERO_WINS;

    }

    if(winningLine.first == lineType::COLUMN) {
        
        if(board[0][winningLine.second] == Player::X)
            return gameStatus::X_WINS;
        return gameStatus::ZERO_WINS;

    }

    if(winningLine.first == lineType::DIAGONAL) {

        if(winningLine.second == 0){

            //main diagonal
            if(board[0][0] == Player::X)
                return gameStatus::X_WINS;
            return gameStatus::ZERO_WINS;

        }

        else {

            //secondary diagonal
            if(board[0][2] == Player::X)
                return gameStatus::X_WINS;
            return gameStatus::ZERO_WINS;

        }

    }

    //check for a draw
    bool draw = true;

    for (int row = 0; row < 3; row++)
        for (int column = 0; column < 3; column++)
            if (board[row][column] == Player::NA)
                draw = false;

    if(draw == true)
        return gameStatus::DRAW;

    return gameStatus::ONGOING;

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

    currentGameStatus = updateGameStatus();

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