#include<iostream>
#include<string>
#include<array>

char switchTurn(char turn){
    if(turn == 'X' || turn == 'x') return 'O';
    return 'X';
}

int minimax(std::array<std::array<char, 3>, 3> b, char turn){
    std::array<std::array<char, 3>, 3> arr;
    int score[3][3];

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            arr[i][j] = b[i][j];
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j] == ' '){
                score[i][j] = minimax(arr, switchTurn(turn));
            }
        }
    }
}

int minimax_wrapper(){}
