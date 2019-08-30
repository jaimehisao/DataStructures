#include <iostream>
#include <string>
#include <map>

using namespace std;

class Teams{
    public:
        string name;
        int numberOfSubmissions;
        int score;
};

Teams::Teams(){
    name = "";
    numberOfSubmissions = 0;
    score = 0;
}


int main(){

    int numberOfTeams, numberOfProblems;
    map<string,Teams> teamMap;
    cin>>numberOfTeams>>numberOfProblems;

    Teams tmpTeam;
    for(int i = 0; i < numberOfTeams; i++){
        Teams tmpTeam;
        cin>>tmpTeam.name;
        teamMap["tmpTeam.name"] = tmpTeam;
    }

    int numberOfSubmssionsSent;

    for(int i = 0; i < numberOfSubmssionsSent; i++){

    }


}