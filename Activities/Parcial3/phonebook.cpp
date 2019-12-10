#include <iostream>
#include <string>
#include <map>

using namespace std;


int main(){
    map <int, string> theMap;
    int times;
    cin>>times;
    
    for(int i = 0; i < times; i++){
        int tmpNum;
        string tmpString, command;

        cin>>command;
        if(command == "add"){
            cin>>tmpNum>>tmpString;
            theMap.erase(tmpNum);
            theMap.insert(pair<int, string>(tmpNum, tmpString));
        }else if(command == "find"){
            cin>>tmpNum;
            if(theMap.count(tmpNum)){
                cout<<theMap[tmpNum]<<endl;
            }else{
                cout<<"not found"<<endl;
            }
        }else if(command == "del"){
            cin>>tmpNum;
            theMap.erase(tmpNum);
        }
    } 
    return 0;
}

//15