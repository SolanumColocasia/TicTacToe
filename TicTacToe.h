//A game of tic tac toe that allows: Users to enter X/O and play tic tac toe.
#include<array>

enum STATE{WON,DRAW,PLAYING};
enum LEVEL{EASY, MEDIUM, HARD};
class Board {

private:
    mutable char turn;
    mutable char winner;    
    LEVEL level;
    std::array<std::array<char, 3>, 3> B;    
    std::array<std::array<int, 3>, 3> score;

    void displayBoard() const;

    void nextTurn() const;

    void putXO();
    
    void greedy();
    
    int minimax(bool, int=0);

    void minimax_wrapper();

    int evaluate_game();

public:
    Board();
    bool checkDraw() const;
    bool checkWin() const;
    void doEverythingSolo();
    void doEverythingDuo();
    void setLevel(LEVEL);
};


