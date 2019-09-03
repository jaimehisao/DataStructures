#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Teams{
        string name = "";
        int numberOfAccepted = 0, score = 0;
        int arr[10] = {0,0,0,0,0,0,0,0,0,0};
};


bool compare(Teams t2, Teams t1){
        return (t1.numberOfAccepted < t2.numberOfAccepted || (t1.numberOfAccepted == t2.numberOfAccepted && t1.score > t2.score));
}

int main(){
    int numberOfTeams, numberOfProblems;
    vector<Teams> teamVector;
    cin>>numberOfTeams>>numberOfProblems;

    for(int i = 0; i < numberOfTeams; i++){
        Teams tmpTeam;
        cin>>tmpTeam.name;
        teamVector.push_back(tmpTeam);
    }

    int numberOfSubmssionsSent;
    cin>>numberOfSubmssionsSent;

    for(int i = 0; i < numberOfSubmssionsSent; i++){
        //Team name, Problem, Time and Accepted or Wrong (A, W)
        int time;
        string name, status;
        char problem;
        cin>>name>>problem>>time>>status;

        for(int j = 0; j < teamVector.size(); j++){
            if(teamVector.at(j).name == name){
                 if(status == "A"){
                    if(teamVector.at(j).arr[problem - 'A'] != 0){
                        teamVector.at(j).score += time + (20 * teamVector.at(j).arr[problem - 'A']);
                        teamVector.at(j).numberOfAccepted++;  
                    }else{
                        teamVector.at(j).score += time;
                        teamVector.at(j).numberOfAccepted++;  
                    }
                }else{
                    teamVector.at(j).arr[problem-'A']++;
        }
            }
        }

    }

    sort(teamVector.begin(), teamVector.end(), compare);

    for(int i = 0; i < teamVector.size(); i++){
        cout<<i+1<<" "<<"-"<<" ";
        cout<<teamVector.at(i).name<<" "<<teamVector.at(i).numberOfAccepted<<" ";
        if(teamVector.at(i).score == 0){
            cout<<"-"<<endl;
        }else{
            cout<<teamVector.at(i).score<<endl;
        }
    }

    return 0;
}   


