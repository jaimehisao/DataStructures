#ifndef queue_h
#define queue_h
#include "node.h"
template <class T>
class queue{
    public:
        queue();
        ~queue();
        void push(T data);
        void pop();
        T front();
        int size();
        bool empty();
    private:
        node<T> *end;
        int sizeQ;
};


template <class T>
queue<T>::queue(){
    end = nullptr;
    sizeQ = 0;
}

template <class T>
queue<T>::~queue(){
    if(sizeQ>0){
        node<T> *curr = end->getNext();
        end->setNext(nullptr);
        end = curr; 
        while(end != nullptr){
            end = end->getNext();
            delete curr; 
            curr = end;    
        }
    }
}

/*
Possible Scenarios for the Push of new data into the Queue.
A.-Queue is empty - Create a new node, and make it point to itself as next
B.- Has one element - Create a new node, point it to the first node, point the end to that node.
C.- Has multiple elements - Create new node, point the new one to the first one, point end node to the newly added one.
*/
template <class T>
void queue<T>::push(T data){
    if(empty()){
        end = new node<T>(data);
        end->setNext(end);
    }else{
        end->setNext(new node<T>(data, end->getNext()));
        end = end->getNext();
    }
    sizeQ++;
}

template <class T>
void queue<T>::pop(){
    node<T> *curr = end->getNext();
    if(end->getNext() == end){
        end = nullptr;
    }else{
        end->setNext(end->getNext()->getNext());
    }
    delete curr;
    sizeQ--;
}

template <class T>
T queue<T>::front(){
    return end->getNext()->getData();
}

template <class T>
int queue<T>::size(){
    return sizeQ;
}

template <class T>
bool queue<T>::empty(){
    return end == nullptr;
}

#endif /*node_h*/