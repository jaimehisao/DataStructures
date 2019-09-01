/*
linkedList.cpp - Implementation of a simple Linked List, this file includes both LinkedList and Node classes, and the Main.
This contains methods to add nodes in the beggining, middle and last.
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
        void addFirst(T data);
        void addLast(T data);
        bool add(T data, int pos);
        void deleteFirst();
        void deleteLast();
        bool change(int posA, int posB);
        T set(T data, int pos);
        T get(int pos);
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
There are different cases in which you can add elements to the linkedList
a) Add at the start, to do this, instantiate a new node, then point its next to null and then point the head to do this. 
Change the head to the new one in this case.
b) Add Last, navigate till the end and then add the node at last, then point it to null. En el caso que solo este head, usar addFirst()
c) Add a node between two nodes. To do this, instantiate the node, point its next to the second node and then point to it from the first.
*/
//Case A - Adds an element to the start of the linkedList
template <class T>
void LinkedList<T>::addFirst(T data){
    head = new node<T>(data,head);
    size++;
}

//Case B - Add an element in the back of the LinkedList
template <class T>
void LinkedList<T>::addLast(T data){
   if(isEmpty()){
       addFirst(data);
   }else{
       node<T> *curr = head;
       while(curr->getNext() != nullptr){
           curr = curr->getNext();
       }
       curr->setNext(new node<T>(data));
       size++;
   }
}

//Case C - Add an element to the specified index in the linkedList. This method will return true successful, and false if not.
template <class T>
bool LinkedList<T>::add(T data, int pos){
    if(pos>size){
        return false;
    } 

    if(pos == 0){
        addFirst(data);
    }else if(pos == size){
        addLast(data);
    }else{
        node<T> *curr = head;   
        for(int i = 1; i < pos; i++){
            curr = curr->getNext();
        }
        curr->setNext(data, curr->getNext());
        size++;
    }
}

/*
There are different cases in which you can delete elements from a linkedList
a) Case A - deletes the first element in the linkedList
b) Case B - deletes the last element in the linkedList
*/

//Case A - deletes the First Node
template <class T>
void LinkedList<T>::deleteFirst(){
    if(!isEmpty()){
        node<T> *curr = head;
        head = head->getNext();
        delete curr;
        size--;
    } 
}

//Case B - deletes the Last Node
template <class T>
void LinkedList<T>::deleteLast(){
    if(size <= 1){
        deleteFirst();
    }else{
        node<T> * curr= head;
        while(curr -> getNext()->getNext() != nullptr){
            curr = curr->getNext();
        }
        delete curr->getNext();
        curr->setNext(nullptr);
        size--;
    }
}

template <class T>
T LinkedList<T>::get(int pos){
    if(!isEmpty()){
        node<T> *curr = head;   
        for(int i = 1; i < pos; i++){
            curr = curr->getNext();
        }
        return curr->getData();
    }
}

template <class T>
T LinkedList<T>::set(T data, int pos){
    if(!isEmpty()){
        node<T> *curr = head;   
        for(int i = 1; i < pos; i++){
            curr = curr->getNext();
        }
        T retInfo = curr->getData();
        curr->setData(data);
        return retInfo;
    }
}

//Exchanges the data in two linkedList positions, then, returns true if possible and false if otherwise
template <class T>
bool LinkedList<T>::change(int posA, int posB){
    if(posA>size && posB>size){
        return false;
    } 

    if(!isEmpty()){
        node<T> *currA = head;   
        node<T> *currB = head;
        for(int i = 1; i < posA; i++){
            currA = currA->getNext();
        }

        for(int i = 1; i < posB; i++){
            currB = currB->getNext();
        }

        T tmpData = currA->getData();
        currA->setData(currB->getData());
        currB->setData(tmpData);

    }
    return true;
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