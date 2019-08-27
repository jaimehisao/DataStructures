/*
sudoku.cpp - This program recieves a sodoku as a matrix and returns if its a valid sudoku or not.
By: Jaime Hisao Yesaki Hinojosa A01720044
Date: 21/8/2019
 */
#include <iostream>

using namespace std;

bool checkLine(int matrix[9][9]){
    int sum;
    for(int i = 0; i < 9; i++){
        sum = 0;
        for(int j = 0; j < 9; j++){
        sum += matrix[i][j];
    }
        if(sum != 45){
            return false;
        }
    }

    return true;
}

bool checkColumn(int matrix[9][9]){
    int sum;
    for(int i = 0; i < 9; i++){
        sum = 0;
        for(int j = 0; j < 9; j++){
        sum += matrix[j][i];
    }
        if(sum != 45){
            return false;
        }
    }

    return true;
}

bool checkQuadrant(int matrix[9][9]){
    int sum = 0;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            sum += matrix[i][j];
    }
    }

    if(sum != 405){
        return false;
        }

    return true;
}

bool checkQuadrant2(int matrix[9][9]){
    int sum;

    for(int i = 0; i < 6; i+=3){
        sum = 0;
        for(int j = 0; j < 9; j++){
            sum += matrix[i][j];
    }
    }

    if(sum != 405){
        return false;
        }

    return true;
}

int main(){

    int sudoku[9][9];

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
        cin>>sudoku[i][j];
    }
    }

    bool lineResult = checkLine(sudoku);
    bool columnResult = checkColumn(sudoku);
    bool quadResult = checkQuadrant(sudoku);

    if(lineResult && columnResult && quadResult){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;

}