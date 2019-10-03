#include "NodeT.h"

class BST{
    public:
        BST();
        ~BST();
        bool search(int data);
        void add(int data);
        void remove(int data);
        void print(int type);//1.-Prints in Preorder 2.-Prints in Inorder 3.-Prints in Postorder
    private:
        NodeT *root;
        int howManyChildren(NodeT *r);
        int succ(NodeT *r);
        int pred(NodeT *r);
};

BST::BST(){
    root = nullptr;
}

BST::~BST(){

}

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

void BST::printLeaves(NodeT *root){

}

//Method that returns the total number of nodes in a given BST
int BST::count(NodeT *root){
    int numOfNodes = 0;

    if(root->getLeft()){
        numOfNodes++;
        numOfNodes+=count(root->getLeft());
    }

    if(root->getRight()){
        numOfNodes++;
        numOfNodes+=count(root->getRight());
    }

    return numOfNodes;
}