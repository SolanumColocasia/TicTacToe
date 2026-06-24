//A game of tic tac toe that allows: Users to enter X/O and play tic tac toe.
#include<array>

class Board {

private:
    mutable char turn;
    mutable char winner;
    std::array<std::array<char, 3>, 3> B;

    void displayBoard() const;

    void nextTurn() const;

    void putXO();    
    

public:
    Board();
    bool checkDraw() const;
    bool checkWin() const;
    void doEverything();
};


