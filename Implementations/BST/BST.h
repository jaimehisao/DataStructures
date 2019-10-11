#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#include "NodeT.h"

class BST{
    public:
        BST();
        ~BST();
        BST(BST &b);
        bool search(int data);
        void add(int data);
        void remove(int data);
        void print(int type);//1.-Prints in Preorder 2.-Prints in Inorder 3.-Prints in Postorder
        void printLeaves();
        int count();
        //Tarea 1 - BST
        int height();
        int whatLevelAmI(int data);
        vector<int> ancestors(int data);
        //Tarea 2 - BST
        int maxWidth(); //
        int nearestRelative(int d1, int d2);
        queue<int> toQueue();
        bool operator ==(BST &b2);
    private:
        NodeT *root;
        int howManyChildren(NodeT *r);
        int succ(NodeT *r);
        int pred(NodeT *r);
        void preorden(NodeT* data);
        void inorden(NodeT* data);
        void postorden(NodeT* data);
        void destruye(NodeT* root);
        void printLeaves(NodeT* root);
        int countPreorden(NodeT *root);
        void printByLevel(NodeT *root);
        int individualHeight(NodeT* root);
        void copyHelper(NodeT* rootA);
        bool equalHelper(NodeT* rootA, NodeT* rootB);
        NodeT* nearestRelativeRecursive(NodeT* nRel, int a, int b);
        void toQueueAssist(queue<int> &tQueue, NodeT* root);
};

/************************************************
*   Constructors and Desctructors for the BST   *
*************************************************/

//Default Constructor
BST::BST(){
    root = nullptr;
}

//Destructor for the BST, calls an auxiliary function to do it recursively.
BST::~BST(){
    destruye(root);
}


/************************************************
*          Operator Overloading for a BST       *
*************************************************/

//Returns True or False depending if the two given BSTs are the same or not.
bool BST::operator ==(BST &b2){
    //Traversing the whole BST will allow us to know if they are exactly the same. We can use any method to traverse it, we'll use preorder for this one.
    NodeT* rootA = b2.root;
    NodeT* rootB = root;
    return equalHelper(rootA, rootB);
}

/************************************************
*     End of Operator Overloading for a BST     *
*************************************************/

/************************************************
*          Private Methods for the BST          *
*************************************************/

//Function that helps the overloaded == operator determine if two trees are equal to each other.
bool BST::equalHelper(NodeT* rootA, NodeT* rootB){
    while(rootA != nullptr){
        if(rootA->getData() != rootB->getData()){
            return false;
        }else{
            if(equalHelper(rootA->getLeft(),rootB->getLeft()) && equalHelper(rootA->getRight(),rootB->getRight())){
                return true;
            }else{
                return false;
            }
    }
}
    return true;
}

//Helper function for the Copy Constructor
void BST::copyHelper(NodeT* rootA){
    if(rootA != nullptr){
        this->add(rootA->getData());
        copyHelper(rootA->getLeft());
        copyHelper(rootA->getRight());
    }
}
//Returns how many children does a given node have.
int BST::howManyChildren(NodeT *r){
    int cont = 0;
    if(r->getLeft() != nullptr){
        cont++;
    }
    if(r->getRight() != nullptr){
        cont++;
    }
    return cont;
}

//Returns the value that is the predecesor to the given node. Successor being one to the right and then on the left till the end.
int BST::succ(NodeT *r){
    NodeT *curr = r->getRight();
    while (curr->getLeft() != nullptr){
        curr = curr->getLeft();
    }
    return curr->getData();
}

//Returns the value that is the predecesor to the given node. Predecesor being one to the Left and then on the right till the end.
int BST::pred(NodeT *r){
    NodeT *curr = r->getLeft();
    while (curr->getRight() != nullptr){
        curr = curr->getRight();
    }
    return curr->getData();
}

//Various Types and Methods for Printing a BST, this are private and called from the print() function.

//Prints the current node (father) and then accesses the children recursively.
void BST::preorden(NodeT* root){
    if(root != nullptr){
        cout<<root->getData()<<" ";
        preorden(root->getLeft());
        preorden(root->getRight());
    }
}

//Prints the left node and then goes up.
void BST::inorden(NodeT* root){
    if(root != nullptr){
        inorden(root->getLeft());
        cout<<root->getData()<<" ";
        inorden(root->getRight());
    }
}

//Prints the right node and then goes up.
void BST::postorden(NodeT* root){
    if(root != nullptr){
        postorden(root->getLeft());
        postorden(root->getRight());
        cout<<root->getData()<<" ";
    }
}

//Method that is called by printLeaves and prints the leaves of the tree, called recursively.
void BST::printLeaves(NodeT* root){
    if(root != nullptr){
        if(root->getLeft() == nullptr && root->getRight() == nullptr){
            cout<<root->getData()<<" ";
        }else{
            printLeaves(root->getLeft());
             printLeaves(root->getRight());
        }
    }
}

//Method that is called by count, traverses the tree using the preorder method and counts the amount of nodes.
int BST::countPreorden(NodeT* root){
    if(root == nullptr){
        return 0;
    }
    return 1 + countPreorden(root->getLeft()) + countPreorden(root->getRight());
}

//Method that prints the tree by level, using a queue. Called by print()
void BST::printByLevel(NodeT* root){
    if(root == nullptr){
        return;
    }

    queue<NodeT*> q;
    q.push(root);

    while(!q.empty()){
        NodeT* tmp = q.front(); 
        if(tmp->getLeft() != nullptr){
            q.push(tmp->getLeft());
        }
        if(tmp->getRight() != nullptr){
            q.push(tmp->getRight());
        }
        cout<<tmp->getData()<<" ";
        q.pop();
    }
}

//!work in progress -- should go in the private section
int BST::individualHeight(NodeT* root){
    int hL, hR;
    if(root == nullptr){
        return 0;
    }

    hL = individualHeight(root->getLeft());
    hR = individualHeight(root->getRight());
return  1+(left > right ? hL : hR);
}

//Method that destroys the tree recursively, frees up the memory used by it.
void BST::destruye(NodeT* root){
    if(root != nullptr){
        destruye(root->getLeft());
        destruye(root->getRight());
        delete root;
    }
}

//Assists the toQueue method by being able to call itself recursively and traverse the tree...
void BST::toQueueAssist(queue<int> &tQueue, NodeT* root){
    while(root != nullptr){
    toQueueAssist(tQueue, root->getLeft());
    tQueue.push(root->getData());
    toQueueAssist(tQueue, root->getRight());
    return;
    }
}

/************************************************
*         END Private Methods for the BST       *
*************************************************/



/************************************************
*           Public Methods for the BST          *
*************************************************/

//Returns True if the data was found in the tree, False if otherwise
bool BST::search(int data){
    NodeT *curr = root;
    while(curr != nullptr){
        if(curr->getData() == data){
            return true;
        }
        curr = (curr->getData() > data ? curr->getLeft() : curr->getRight()); //Ternary Operator
    }
    return false;
}

//Adds a piece of data into the tree.
void BST::add(int data){
    NodeT *curr = root;
    NodeT *father = nullptr;
    while(curr != nullptr){
        if(curr->getData() == data){
            //Can't add since its duplicated...
            return;
        }
        father = curr;
        curr = (curr->getData() > data ? curr->getLeft() : curr->getRight());
    }
    if(father == nullptr){
        root = new NodeT(data);
    }else{
        if(father->getData() > data){
            father->setLeft(new NodeT(data));
        }else{
            father->setRight(new NodeT(data));
        }
    }
}

//Removes a given data node from the BST
void BST::remove(int data){
    NodeT *curr = root;
    NodeT *father = nullptr;
    //Given the order of operations in C++, if the first element in && is false, the second wont be executed.
    while(curr != nullptr && curr->getData() != data){
        father = curr;
        curr = (curr->getData() > data ? curr->getLeft() : curr->getRight());
    }

    if(curr == nullptr){
        return;
    }

    int cantHijos = howManyChildren(curr);

    //Switch case dependent on the number of children of the given tree.
    switch (cantHijos){
    case 0:
        //Case when father is the only element in the BST
        if(father == nullptr){
            root = nullptr;
        }else{
            //Case when the element to delete is not the first element, but has no children.
            if(father->getData() > data){
                father->setLeft(nullptr);
            }else{
                father->setRight(nullptr);
            }
        }
        delete curr;
        break;
    case 1:
        //Case when you know that the Node has 1 child, but not if its left or right nor what the father is. 
        //The case of when you want to delete the root element also applies here (father of root is nullptr)
        //Case of Root Deletion
        if(father == nullptr){ 
            //Case of Root Deletion
            if(curr->getLeft() != nullptr){
                root = curr->getLeft();
            }else{
                root = curr->getRight();
            }
        }else{ //Checks if the child of the node is left or right, the first if is for case of smaller value, else if bigger value.
            if(father->getData() > data){
                if(curr->getLeft() != nullptr){
                    father->setLeft(curr->getLeft());
                }else{
                    father->setLeft(curr->getRight());
                }
            }else{
                if(curr->getLeft() != nullptr){
                    father->setRight(curr->getLeft());
                }else{
                    father->setRight(curr->getRight());
                }
            }
        }
        delete curr;
        break;
    case 2: 
        //Case when the Node has two children, using the succ or pred methods.
        int dataSucc = succ(curr);
        remove(dataSucc);
        curr->setData(dataSucc);
        break;
    }
}

//Method that prints the leaves of a BST, uses a helper function which is private.
void BST::printLeaves(){
    //Empty Tree Case
    if(root == nullptr){
        return;
    }

    queue<NodeT*> q;
    q.push(root);

    while(!q.empty()){
        NodeT* tmp = q.front(); 
        if(tmp->getLeft() != nullptr){
            q.push(tmp->getLeft());
        }
        if(tmp->getRight() != nullptr){
            q.push(tmp->getRight());
        }

        if(tmp->getLeft() == nullptr && tmp->getLeft() == nullptr){
            cout<<tmp->getData()<<" ";
        }
        q.pop();
    }
}

//Method that returns the total number of nodes in a given BST, calls a helper function which is private.
int BST::count(){
    return countPreorden(root);
}

//Returns the maximum height of the BST, calls a helper function which is private.
int BST::height(){
    return individualHeight(root);
}

//Returns a vector that contains the ancestors of the given node in the BST, if the tree is empty, returns an empty vector.
vector<int> BST::ancestors(int data){
    vector<int> theAncestors; 
    bool exists = false;
    NodeT *curr = root;
    while(curr != nullptr){
        if(curr->getData() == data){
            exists = true;
            return theAncestors;
        }
        if(curr->getData() > data){
            theAncestors.push_back(curr->getData());
            curr = curr->getLeft();
        }else{
            theAncestors.push_back(curr->getData());
            curr = curr->getRight();
        }
    }
    vector<int> ret;
    return ret;
}

//Returns the level where a given piece of data is inside the BST.
int BST::whatLevelAmI(int data){
    int level = 0;
    NodeT *curr = root;
    while(curr != nullptr){
        if(curr->getData() == data){
            return level;
        }
        if(curr->getData() > data){
            curr = curr->getLeft();
            level++;
        }else{
            curr = curr->getRight();
            level++;
        }
    }
    return -1;
}

//Function that recieves a print type and prints the BST acordingly.
void BST::print(int type){
    switch(type){
        case 1: preorden(root);
                break;
        case 2: inorden(root);
                break;
        case 3: postorden(root);
                break;
        case 4: printLeaves(root);
                break;
        case 5: printByLevel(root);
                break;
    }
    cout<<endl;
}