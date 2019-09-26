 /*
linkedList.h
Jaime Hisao Yesaki H A01720044
Estructura de Datos
*/
template <class T>
class LinkedList{
    public:
        LinkedList(); 
        LinkedList(LinkedList &l);
        ~LinkedList(); 
        bool isEmpty(); 
        int getSize();
        void addFirst(T data);
        void addLast(T data);
        bool add(T data, int pos);
        void deleteFirst();
        void deleteLast();
        void del(int pos);
        int deleteAll();
        bool change(int posA, int posB);
        T set(T data, int pos);
        T get(int pos);
        void print();
        void reverse();
        bool operator == (const LinkedList<T> &other);
        void operator += (T data);
        void operator += (const LinkedList<T> &l);
        void operator = (const LinkedList<T> &l);
    private:
        node<T> *head;
        int size;
        void deleteAllList();
};

//Starts a LinkedList with a NULL head and a size of 0
template <class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    size = 0;
}

//Copies a LinkedList
template <class T>
LinkedList<T>::LinkedList(LinkedList &l){
    node<T> curr = head; 
    node<T> currB = l.head;
    while(currB != nullptr){
        curr->setNext(currB->getData());
        curr = curr->getNext();
        currB = currB->getNext();
   }
}

template <class T>
LinkedList<T>::~LinkedList(){
    deleteAllList();
}

//Total LinkedList Destructor (not object destructor, but called by it)
template <class T>
void LinkedList<T>::deleteAllList(){
    node<T> *curr = head;
    while(curr != nullptr){
        cout<<"mmmm";
        delete curr;
        curr = curr->getNext();
        head = curr;
        //delete curr;
        //curr = head; //???
    }
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

//Deletes a node in the given position, this assumes that the position sent to it is already validated.
template <class T>
void LinkedList<T>::del(int pos){
    if(pos == 0){
        deleteFirst();
    }else{
       node<T> *curr = head;   
        for(int i = 1; i < pos; i++){
            curr = curr->getNext();
        }
        node<T> *aux = curr->getNext();
        curr->setNext(aux->getNext());
        delete aux;
        size--;
    }
}

//Delete All of the Nodes of the LinkedList, basically leave it as new.
template <class T>
int LinkedList<T>::deleteAll(){
    deleteAllList();
    int auxSize = size;
    size = 0;
    return auxSize;
}

//Gets the data of the given node position, and returns it.
template <class T>
T LinkedList<T>::get(int pos){
    if(!isEmpty()){
        node<T> *curr = head;   
        for(int i = 1; i <= pos; i++){
            curr = curr->getNext();
        }
        return curr->getData();
    }
}

//Sets the value of the given node position with the given data, returns the data of the replaced node.
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
    //Teachers Implementation
    if(posA < 0 || posB < 0 || posA >= size || posB >= size){
        return false;
    } 

    if(posA == posB){
        return true;
    }

    //Conditional operator, first part is the condition, second part is the TRUE : FALSE cases.
    int posMen = (posA < posB ? posA : posB);
    int posMay = (posA > posB ? posA : posB);

    node<T> *curr1 = head;
    for(int i = 1; i <= posMen; i++){
        curr1 = curr1->getNext();
    }
    node<T> *curr2 = curr1;
    for(int i = posMen; i<posMay; i++){
        curr2 = curr2->getNext();
    }

    T dataAux = curr1->getData();
    curr1->setData(curr2->getData());
    curr2-setData(dataAux);
    return true;
}

//Displays the contents of the LinkedList, from start to finish.
template <class T>
void LinkedList<T>::print(){
    node<T> *curr = head;
    while(curr != nullptr){
        cout<<curr->getData()<<endl;
        curr = curr->getNext();
    }
}

//Reverses the contents of the LinkedList. Gets the First element, gets the address of the next element and moves on.
template <class T>
void LinkedList<T>::reverse() {
    node<T> *curr1 = head;
    node<T> *curr2 = curr1->getNext();
    node<T> *prev = nullptr;
    
    while (head != nullptr){
        head = curr1->getNext();
        curr2 = curr1->getNext();
        curr1->setNext(prev);
        prev = curr1;
        curr1 = head;
    }
    head = prev;
}

//***************** Operator Overloading ****************
//Returns true if two LinkedLists are equal to one another, contents, order and size.
template <class T>
bool LinkedList<T>::operator == (const LinkedList<T> &b){
    node<T> *curr = this->head;
    node<T> *currB = b.head;

    if(this->size != b.size){
        return false;
    }

    for(int i = 0; i < size; i++){
        if(curr->getData() != currB->getData()){
            return false;
        }else{
            curr = curr->getNext();
            currB = currB->getNext();
        }
    }
    return true;
}

//Adds a single node to the end of a given LinkedList. Calls the addLast, thus resulting in high inefficiency.
template <class T>
void LinkedList<T>::operator += (T data){
    this->addLast(data);
}

//Recieves a LinkedList and adds it to the end of the current LinkedList
template <class T>
void LinkedList<T>::operator += (const LinkedList<T> &l){
    node<T> *curr = this->head;

    while(curr != nullptr){
        curr = curr->getNext();
    }

    node<T> *currB = l.head;
    while(currB != nullptr){
        node<T> *data = new node<T> (currB->getData());
        curr->setNext(data);
        currB = currB->getNext();
        curr = curr->getNext();
    }
}

//Equals the current LinkedList to the given LinkedList (complete overwrite of the first LinkedList)
template <class T>
void LinkedList<T>::operator = (const LinkedList<T> &l){
    this->deleteAll();
    this->head = l.head;
    node<T> *currL = l.head;
    node<T> *currNew= this->head;
    while(currL != nullptr)
        currNew->setNext(currL);
        currNew->getNext(); 
        node<T> * aux;
        aux = currL->getNext();
    }



/*
END OF LINKED LIST CLASS
*/