/*
BST.cpp - Class that implements a Binary Search Tree and its methods
By: Jaime Hisao Yesaki Hinojosa A01720044
Created: 25/9/19
*/
#import <iostream>
#import <queue>
using namespace std;

/*
NODE CLASS STARTS
*/
class NodeT{
    public:
        NodeT(int data);
        int getData();
        void setData(int data);
        NodeT* getLeft();
        NodeT* getRight();
        void setLeft(NodeT *left);
        void setRight(NodeT *right);
    private:
        int data;
        NodeT *left;
        NodeT *right;
};

NodeT::NodeT(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

int NodeT::getData(){
    return data;
}

void NodeT::setData(int data){
    this->data = data;
}

NodeT* NodeT::getLeft(){
    return left;
}

NodeT* NodeT::getRight(){
    return right;
}

void NodeT::setLeft(NodeT* left){
    this->left = left;
}

void NodeT::setRight(NodeT* right){
    this->right = right;
}


/*
NODE CLASS ENDS
*/

/*
BST CLASS STARTS
*/

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
        int height();
        int whatLevelAmI(int data);
        vector<int> ancestors(int data);
        int maxWidth();
        int nearestRelative(int d1, int d2);
        queue<int> toQueue();
        bool operator ==(BST b2);
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

//Copy Constructor for a BST
BST::BST(BST &b2){
    //Traversing the BST using the Preorder method will allow us to copy the BST to another BST.
    cout<<b2.root;
    //copyHelper(b2.root);
}

/************************************************
*          Operator Overloading for a BST       *
*************************************************/

bool BST::operator ==(BST b2){
    return false;
}

/************************************************
*          Private Methods for the BST          *
*************************************************/

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
void BST::preorden(NodeT* root){
    if(root != nullptr){
        cout<<root->getData()<<" ";
        preorden(root->getLeft());
        preorden(root->getRight());
    }
}

void BST::inorden(NodeT* root){
    if(root != nullptr){
        inorden(root->getLeft());
        cout<<root->getData()<<" ";
        inorden(root->getRight());
    }
}

void BST::postorden(NodeT* root){
    if(root != nullptr){
        postorden(root->getLeft());
        postorden(root->getRight());
        cout<<root->getData()<<" ";
    }
}

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

int BST::countPreorden(NodeT* root){
    if(root == nullptr){
        return 0;
    }
    return 1 + countPreorden(root->getLeft()) + countPreorden(root->getRight());
}

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

int BST::individualHeight(NodeT* root){
    int height = 0, h1 = 1,h2 = 1;
    if(root != nullptr){
        h1 = individualHeight(root->getLeft());
        h2 = individualHeight(root->getRight());
        if(h1>h2){
        height+=h1;
    }else{
        height+=h2;
    }
    }
return  height;
}

void BST::destruye(NodeT* root){
    if(root != nullptr){
        destruye(root->getLeft());
        destruye(root->getRight());
        delete root;
    }
}

/************************************************
*         END Public Methods for the BST        *
*************************************************/



/************************************************
*           Public Methods for the BST          *
*************************************************/


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



//Method that prints the leaves of a BST
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

//Method that returns the total number of nodes in a given BST - using a queue
int BST::count(){
    return countPreorden(root);
    /*
    if(root == nullptr){
        return 0;
    }

    queue<NodeT*> q;
    int numOfNodes = 1;
    q.push(root);

    while(!q.empty()){
        NodeT* tmp = q.front(); 
        if(tmp->getLeft() != nullptr){
            q.push(tmp->getLeft());
            numOfNodes++;
        }
        if(tmp->getRight() != nullptr){
            q.push(tmp->getRight());
            numOfNodes++;
        }
        q.pop();
    }
    return numOfNodes;
    */
}


//Returns the maximum height of the BST
int BST::height(){
    return individualHeight(root);
}



//Returns a vector that contains the ancestors of the given node in the BST
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
    }
    cout<<endl;
}

int BST::maxWidth(){
    int mWidth = 0;

    return mWidth;
}

int BST::nearestRelative(int d1, int d2){
    int theRelative = 0;
    return theRelative;
}

queue<int> BST::toQueue(){
    queue<int> q;
    return q;
}

/*
BST CLASS ENDS
*/



//Preorden es el recorrido que nos sirve para copiar 

//Testing component of the application.
int main(){

    BST tree;
    tree.add(20);
    tree.add(50);
    tree.add(44);
    tree.add(10);
    tree.add(15);
    tree.add(9);
    tree.add(5);
    tree.add(100);
    tree.add(60);
    tree.add(8);
    tree.print(1);
    tree.print(2);
    tree.print(3);

    if(tree.search(8)){
        cout<<"Si esta el 8"<<endl;
    }else{
        cout<<"No esta el 8"<<endl;
    }
    if(tree.search(10)){
        cout<<"Si esta el 10"<<endl;
    }else{
        cout<<"No esta el 10"<<endl;
    }
    if(tree.search(80)){
        cout<<"Si esta el 80"<<endl;
    }else{
        cout<<"No esta el 80"<<endl;
    }

    cout<<"dame un dato..."<<endl;
    //int dato;
    //cin>>dato;
    //tree.remove(dato);

    tree.print(1);
    tree.print(2);
    tree.print(3);
    cout<<"Las Hojas Son...";
    tree.print(4);
    cout<<"Cantidad de Datos..."<<tree.count()<<endl;
    cout<<tree.whatLevelAmI(69)<<endl;

    vector<int> theAncestors = tree.ancestors(69);
    for(int i = 0; i < theAncestors.size(); i++){
        cout<<theAncestors.at(i)<<" ";
    }

    cout<<"Level by level: ";
    tree.print(5);

    cout<<"Tree height: "<<tree.height()<<endl;
    //tree.~BST(); 

    cout<<"Copying Tree to New BST"<<endl;
    BST tree2(tree);
    tree2.print(4);

    return 0;
}