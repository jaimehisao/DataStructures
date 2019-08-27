/*
Problema1.cpp - This program recieves number n which is the number of flips to do. Then recieves values for
a 4x4 matrix. 
By: Jaime Hisao Yesaki Hinojosa A01720044
Date: 15/8/2019
 */
#include <iostream>
using namespace std;

//Prints the Matrix 
void display(int matrix[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<matrix[i][3]<<endl;
    }
}

void flip2(int matrix[4][4]){
    int matrix2[4][4];
    int x = 0;
    for(int i=0; i<4;i++){
        for(int j=3; j>=0;j--){     
            matrix2[i][x++] = matrix[j][i]; 
        }
         x = 0;
}

    for(int i=0; i<=4;i++){
        for(int j=0; j<=4;j++){
        matrix[i][j] = matrix2[i][j]; 
        }
    }

}


//The Flip Part
void flip(int matrix[4][4]){
    int matrixTemp[4][4];

    //Flipiwipi
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            matrixTemp[i][4 - j - 1] = matrix[i][j];
        }
    }
    
     //Copy Tmp to Matrix
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            matrix[i][j] = matrixTemp[i][j];
        }
    }
}


int main(){

    int matrix[4][4];
    int movement;
    cin>>movement;

    if(movement < 0){
        movement = movement % 4 + 4;
    }else{
        movement = movement % 4;
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin>>matrix[i][j];
        }
    }

    for(int i = 0; i < movement; i++){
        flip2(matrix);
    }


   display(matrix);


    return 0;
}