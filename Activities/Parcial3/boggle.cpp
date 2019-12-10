#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Struct that will hold the leters and if the place has been visited or not.
struct boardPieces{
    char board[4][4];
    bool boardVisited[4][4] = {{false}};
};

//Finds the words inside the Boggle Matrix
void resolverHelper(struct boardPieces board, int i, int j, string current){ 
    board.boardVisited[i][j] = true;
    current = current + board.board[i][j];
    
    if(isInDictionary(current)){

    }

}

//Checks if the word that was found is inside the valid dictionary.
bool isInDictionary(vector<string> dict, string word){
    for(int i = 0; i < dict.size(); i++){
        if(word.compare(dict.at(i))){
            return true;
        }
    }
    return false;
}

int main(){
    int nGames, nWords;
    vector<string> wordDic;
    boardPieces theBoard;
    cin>>nGames;

    //Recieves the board.
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin>>theBoard.board[i][j];
        }
    }

    //Recieves the Dictionarys as many times and many games as inserted.
    for(int i = 0; i < nGames; i++){
        cin>>nWords;
        for(int j = 0; j < nWords; j++){
            string tmp;
            cin>>tmp;
            wordDic.push_back(tmp);
        }
    }
    //Start Solving
    string current = "";

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            resolverHelper(board, i, j, current);
        }
    }

    return 0;
}