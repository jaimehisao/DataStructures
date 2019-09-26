#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <sstream>


using namespace std;

//This function pushes to the Priority Queue, Queue, and Stack. The DS are passed by reference to the method.
void pushTo(string toPass, priority_queue<int, std::vector<int>, std::greater<int> > &pq, queue<int> &q, stack<int> &s){
    pq.push(stoi(toPass));
    q.push(stoi(toPass));
    s.push(stoi(toPass));
}

void proccesOperand(string operand, priority_queue<int, std::vector<int>, std::greater<int> > &pq, queue<int> &q, stack<int> &s){

    if(operand == "+"){
        //Pushes to the Priority Queue
        int tmp = pq.top();
        pq.pop();
        tmp += pq.top();
        pq.pop();
        pq.push(tmp);

        //Pushes to the Queue
        tmp = q.front();
        q.pop();
        tmp += q.front();
        q.pop();
        q.push(tmp);

        //Pushes to the Stack
        tmp = s.top();
        s.pop();
        tmp += s.top();
        s.pop();
        s.push(tmp);
    }else if(operand == "-"){
        //Pushes to the Priority Queue
        int tmp = pq.top();
        pq.pop();
        tmp = pq.top() - tmp;
        pq.pop();
        pq.push(tmp);

        //Pushes to the Queue
        tmp = q.front();
        q.pop();
        tmp = q.front() - tmp;
        q.pop();
        q.push(tmp);

        //Pushes to the Stack
        tmp = s.top();
        s.pop();
        tmp = s.top() - tmp;
        s.pop();
        s.push(tmp);
    }else if(operand == "*"){
        //Pushes to the Priority Queue
        int tmp = pq.top();
        pq.pop();
        tmp *= pq.top();
        pq.pop();
        pq.push(tmp);

        //Pushes to the Queue
        tmp = q.front();
        q.pop();
        tmp *= q.front();
        q.pop();
        q.push(tmp);

        //Pushes to the Stack
        tmp = s.top();
        s.pop();
        tmp *= s.top();
        s.pop();
        s.push(tmp);

    }else if(operand == "/"){
        //Pushes to the Priority Queue
        int tmp = pq.top();
        pq.pop();
        tmp = pq.top() / tmp;
        pq.pop();
        pq.push(tmp);

        //Pushes to the Queue
        tmp = q.front();
        q.pop();
        tmp = q.front() / tmp;
        q.pop();
        q.push(tmp);

        //Pushes to the Stack
        tmp = s.top();
        s.pop();
        tmp = s.top() / tmp;
        s.pop();
        s.push(tmp);
    }

}

int main(){

    string d,data;
    priority_queue<int, std::vector<int>, std::greater<int> > pQueue;
    queue<int> tQueue;
    stack<int> tStack;
    getline(cin, data);
    while (data != "#"){
	    stringstream ss;
  	    ss << data;
	    while (ss >> d){
		if(d != "+" && d != "-" && d != "*" && d != "/" && d != " "){
                pushTo(d, pQueue, tQueue, tStack);
            }else if(d != " "){
                proccesOperand(d, pQueue, tQueue, tStack);
        }
	    }
  	    getline(cin, data);	
        cout<<tStack.top()<<" "<<tQueue.front()<<" "<<pQueue.top()<<endl;
        tStack.pop();
        tQueue.pop();
        pQueue.pop();
}


    return 0;
}
