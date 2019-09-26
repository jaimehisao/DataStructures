#include <iostream>
using namespace std;
#include "queue.h"

int main(){
    queue<char> myQueue;
    myQueue.push('A');
    myQueue.push('B');
    myQueue.push('C');
    cout<<"Size: "<<myQueue.size()<<endl;
    cout<<"Front:  "<<myQueue.front()<<endl;
    myQueue.push('D');
    while(!myQueue.empty()){
        cout<<myQueue.front()<<" ";
        myQueue.pop();
    }
    cout<<endl;
}