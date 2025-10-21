//A game of tic tac toe that allows: Users to enter X/O and play tic tac toe.

#include<iostream>
#include<iomanip>
#include<string>
#include<ctype.h>

// using namespace std;

class Board{
    char B[3][3];
    std::string name1;
    std::string name2;
    char turn;
    public:
    Board(){ 
        //constructor to clear the board
        for(int i = 0; i<3;i++){
            for(int j = 0; j<3;j++){
                B[i][j] = ' ';
            }
        }
        turn = 'X';
    }
        
    //displaying the board
    void displayBoard(){
        std::cout<<"\n"<<"  A   B   C \n";
        for(int i=0;i<3;i++){
            std::cout<<i+1<<" "<<B[i][0]<<" | "<<B[i][1]<<" |` "<<B[i][2];
           if(i<2){std::cout<<"\n"<<" ---+---+---"<<"\n";}
        }
    }

    
     // returns the character the user plays.
    void whoseTurnNext(){
        if (turn == 'X'){turn = 'O';} 
        else {turn = 'X';}
    }
      
    
    //getting user choice on board
    void putXO() {
        int i=0,j=0;
        char a;
        while (true) {
            std::cout<<"\n"<<turn<<" plays now.\n";
            std::cout<<"Please enter horizontal coordinate for your piece to go to (eg: 1): ";
            std::cin>>i;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout<<"Invalid input, please enter a number."<<std::endl;
                continue;
            }
            std::cout<<"Please enter vertical coordinate for your piece to go to (eg: A): ";
            std::cin>>a;
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
            else{
                if(B[i-1][j] == ' '){
                    B[i-1][j] = turn;
                    break;
                }
            }
        }
        whoseTurnNext();
    }

    
    bool checkWin(){ //checks for wins
        
        //horizontal check
        for(int i = 0; i<3;i++){
            
            if(B[i][0] != ' '){
                if(B[i][0]==B[i][1] && B[i][0]==B[i][2]){
                    std::cout<<"\n"<< B[i][1] <<" has won!\n";
                    return true;
                }
            }
        }
        

        //vertical check
        for(int j = 0; j < 3; j++){
            if(B[0][j] != ' '){
                if(B[0][j]==B[1][j] && B[0][j]==B[2][j]){
                    std::cout<<"\n"<<B[0][j]<<" has won!\n";
                    return true;
                }
            }
        }

        //diagonal check
        if(B[1][1] != ' '){
            if(B[0][0] == B[1][1] && B[0][0] == B[2][2]){
                std::cout<<"\n"<<B[1][1]<<" has won!";
                return true;
            }
            else if (B[0][2] == B[1][1] && B[0][2] == B[2][0]){
                std::cout<<"\n"<<B[1][1]<<" has won!";
                return true;
            }
        }
        return false;
    }

    void checkDraw(){ 
        int count = 0;
        if(checkWin() == false){    
            for(int i = 0; i<3;i++){
                for(int j = 0; j<3; j++){
                    if(B[i][j] == ' '){
                        break;
                    }
                    else 
                        count ++;
                }
            }
                
            if(count == 9){
                displayBoard();
                std::cout<<"\nThe game is a draw.";
                exit(0);
            }
        }
    }

    void doEverything(){
            displayBoard();
            putXO();
            checkDraw();
            //checkWin();
    }
};

int main(){
    Board b;
    std::cout<<"\nThis is a tictactoe game.";
    do{
        b.doEverything();
    }while(b.checkWin() == false);
    return 0;
}

