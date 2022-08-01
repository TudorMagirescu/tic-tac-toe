#include "graphics.h"

void Graphics :: drawGameBoard(gameWindow& gameWindow){   
    //draw the tic-tac-toe grid

    //draw the vertical lines
    for(int lineIndex=0; lineIndex<4; lineIndex++){
        
        //each line has a width of 3 and a length of 3/4 of the screen
        float width = 3;
        float height = 3 * BOARD_HEIGHT / 4;

        //vertical lines will be placed at 1/8, 3/8, 5/8 and 7/8 of the screen
        float position_x = BOARD_WIDTH / 8 + lineIndex * BOARD_WIDTH / 4;
        float position_y = BOARD_HEIGHT / 8;

        gameWindow.drawRectangle(width, height, position_x, position_y);
    }

}