/*
linkedList.cpp - Implementation of a simple Linked List, this file includes both LinkedList and Node classes, and the Main.
By: Jaime Hisao Yesaki Hinojosa A01720044
Date: 27/8/2019
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
START OF NODE CLASS
 */

template <class T>
class node{
    public:
        node(T data);
        node(T data, node<T>* next);
        T getData();
        node<T>* getNext();
        void setData(T data);
        void setNext(node<T> *next);
    private:
        T data;
        node<T> *next;
};

//Contructor that includes data and also a Null pointer for the next element
template <class T>
node<T>::node(T data){
    this->data = data;
    this->next = nullptr;
}

//Constructor that specifies the next node pointer, with the data.
template <class T>
node<T>::node(T data, node<T> *next){
    this->data = data;
    this->next = next;
}

template <class T>
T node<T>::getData(){
    return this->data;
}

template <class T>
node<T>* node<T>::getNext(){
    return this->next;
}

template <class T>
void node<T>::setData(T data){
    this->data = data;
}

template <class T>
void node<T>::setNext(node<T> *next){
    this->next = next;
}


/*
END OF NODE CLASS
 */



/*
START OF LINKED LIST CLASS
*/
template <class T>
class LinkedList{
    public:
        LinkedList();
        bool isEmpty();
        int getSize();
    private:
        node<T> *head;
        int size;
};

//Starts a LinkedList with a NULL head and a size of 0
template <class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    size = 0;
}

//Returns true is the linked list is empty, false if otherwise
template <class T>
bool LinkedList<T>::isEmpty(){
    return size == 0;
    //return head == nullptr; //Tambien este funciona y tiene el mismo proposito
}

//Returns the size of the LinkedList
template <class T>
int LinkedList<T>::getSize(){
    return size;
}

/*
END OF LINKED LIST CLASS
*/



/*
MAIN
*/
int main(){



    return 0;
}