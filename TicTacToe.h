//A game of tic tac toe that allows: Users to enter X/O and play tic tac toe.

class Board {

private:
    mutable char turn;
    mutable char winner;
    char B[3][3];

    void displayBoard() const;

    void nextTurn() const;

    void putXO();    
    

public:
    Board();
    bool checkDraw() const;
    bool checkWin() const;
    void doEverything();
};


