#include<iostream>
using namespace std;
#include "Priority.h"

int main(){
    Priority pQ;

    pQ.push(1);
    pQ.push(2);
    pQ.push(3);
    pQ.push(4);

    cout<<pQ.top();


    return 0;
}