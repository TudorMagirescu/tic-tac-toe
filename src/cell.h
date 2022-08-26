enum class Player{
    //Each board cell has one of the following states, depending on which player marked it.
    //X and Zero are the two players
    //NA means that the cell is unoccupied
    
    X,
    Zero,
    NA
};

struct Cell {

    Player player;
    bool isBlinking;

    Cell();

};