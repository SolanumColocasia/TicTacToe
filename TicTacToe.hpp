//A game of tic tac toe that allows: Users to enter X/O and play tic tac toe.

#include "TicTacToe.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<cctype>

/// using namespace std;
Board::Board(){ 
    //constructor to clear the board
    for(int i = 0; i<3;i++){
        for(int j = 0; j<3;j++){
            B[i][j] = ' ';
        }
    }
    turn = 'X';
}
        
/// displaying the board
void Board::displayBoard() const {
    std::cout<<"\n"<<"  A   B   C \n";
    for(int i=0;i<3;i++){
        std::cout<<i+1<<" "<<B[i][0]<<" | "<<B[i][1]<<" | "<<B[i][2];
        if(i<2){std::cout<<"\n"<<" ---+---+---"<<"\n";}
    }
}

    
/// returns the character the user plays.
void Board::nextTurn() const{
    this->turn = this->turn == 'X' ? 'O' : 'X';
}
      
    
//getting user choice on board
void Board::putXO() {
    int i=0,j=0;
    char a;
    while (true) {
        std::cout<<"\n"<<turn<<" plays now.\n";
        std::cout<<"Please enter horizontal and vertical coordinate for your piece to go to (eg: 1 A): ";
        std::cin>>i>>a;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout<<"Invalid input, please enter the horizontal coordinate first(a number).\n";
            continue;
        }
        a = toupper(a);
        j=a-'A';
        if(i !=1 && i!=2 && i!=3){                           //checks for row values
            std::cout<<"\nInvalid input, horizontal coordinate is wrong. Please try again.\n";
        }
        else if(a != 'A' && a != 'B' && a!= 'C'){           //checks for coloumn values
            std::cout<<"\nInvalid input, vertical coordinate is wrong. Please try again.\n";
        }
        else if(B[i-1][j] != ' '){                          //checks for filled spaces
            std::cout<<"\nInvalid input, the space is alrady filled! Please try again.\n";
        }
        else {
            B[i-1][j] = turn;
            break;
        }
    }
}

    
bool Board::checkWin() const { //checks for wins   
    //horizontal check
    for(int i = 0; i<3;i++){        
        if(B[i][0] != ' '){
            if(B[i][0]==B[i][1] && B[i][0]==B[i][2]){
                winner = B[i][1];
                return true;
            }
        }
    }
        

    //vertical check
    for(int j = 0; j < 3; j++){
        if(B[0][j] != ' '){
            if(B[0][j]==B[1][j] && B[0][j]==B[2][j]){
                winner = B[0][j]; // std::cout<<"\n"<<B[0][j]<<" has won!\n";
                return true;
            }
        }
    }

    //diagonal check
    if(B[1][1] != ' '){
        if(B[0][0] == B[1][1] && B[0][0] == B[2][2]){
            winner = B[1][1]; //std::cout<<"\n"<<B[1][1]<<" has won!";
            return true;
        }
        else if (B[0][2] == B[1][1] && B[0][2] == B[2][0]){
            winner = B[1][1]; //std::cout<<"\n"<<B[1][1]<<" has won!";
            return true;
        }
    }
    return false;
}

bool Board::checkDraw() const{  
    for(int i = 0; i<3;i++){
        for(int j = 0; j<3; j++){
            if(B[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

void Board::doEverythingDuo(){
    displayBoard();
    putXO();
    nextTurn();
    if(checkWin()){
        std::cout<<"\n"<<winner<<" has won!\n";
    }
    else {
        if(checkDraw()){
        std::cout<<"\nThe game is a draw.\n";
        }
    }        
}

void Board::minimax_wrapper(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            score[i][j] = 0;
        }
    }

    minimax(true);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(B[i][j] == ' '){
                if(score[i][j] == 1){
                    B[i][j] = turn;
                    return;
                }
            }
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(B[i][j] == ' '){
                if(score[i][j] == 0){
                    B[i][j] = turn;
                    return;
                }
            }
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(B[i][j] == ' '){
                if(score[i][j] == -1){
                    B[i][j] = turn;
                    return;
                }
            }
        }
    }
}

int Board::minimax(bool maximise){    
    int best;
    if(maximise) {
        best = -10;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(B[i][j] == ' '){
                    int current_score;
                    B[i][j] = turn; // temporarily add to board
                    if(checkWin()){
                        current_score = 1;
                    }
                    else if (checkDraw()){
                        current_score = 0;
                    }
                    else{                        
                        nextTurn(); // temporarily switch turn
                        current_score = minimax(false);
                        nextTurn(); // reset turn
                    }
                    B[i][j] = ' '; // reset board
                    score[i][j] = current_score;
                    best = (current_score>best) ? current_score:best;
                }
            }
        }
        return best;
    }

    else {
        best = 10;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(B[i][j] == ' '){
                    int current_score;
                    B[i][j] = turn; // temporarily add to board
                    if(checkWin()){
                        current_score = -1;
                    }
                    else if (checkDraw()){
                        current_score = 0;
                    }
                    else{                        
                        nextTurn(); // temporarily switch turn
                        current_score = minimax(true);
                        nextTurn(); // reset turn
                    }
                    B[i][j] = ' '; // reset board
                    best = (current_score<best) ? current_score:best;
                }
            }
        }
        return best;
    }
}

void Board::doEverythingSolo(){
    displayBoard();
    putXO();
    nextTurn();    
    if(checkWin()){
        std::cout<<"\n"<<winner<<" has won!\n";
    }
    else if(checkDraw()){
        std::cout<<"\nThe game is a draw.\n";
    }
    else{ 
        minimax_wrapper();    
        nextTurn();
        if(checkWin()){
            std::cout<<"\n"<<winner<<" has won!\n";
        }
        else if(checkDraw()){
            std::cout<<"\nThe game is a draw.\n";
        }
    }
}

int main(){
    Board b;
    int choice;
    std::cout<<std::setfill('-')<<std::setw(30)<<""<<std::endl;
    std::cout<<"\tTic Tac Toe"<<std::endl;
    std::cout<<std::setfill('-')<<std::setw(30)<<""<<std::endl;

    std::cout<<"Rules: \nThis is a classic 2 player Tic tac toe game, where the first player to align their respectice piece (X or O) wins.\n";
    std::cout<<"This can take place either across rows, columns or along the 2 main diagonals.\n";

    
    std::cout<<"\nFor solo play with AI enter [1], for pass and play enter [2]. To quit enter [CTRL + C].\n";
    std::cin>>choice;
       
    if(choice == 1) {
        do{
            b.doEverythingSolo();
        }while(!b.checkWin() && !b.checkDraw());
    }
    else if(choice == 2) {
        do{
            b.doEverythingDuo();
        }while(!b.checkWin() && !b.checkDraw());
    }
    return 0;
}