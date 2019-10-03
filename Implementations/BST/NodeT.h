//Due to the fact that thids is a BST, the elements have to know which one is bigger or smaller. 
//But we're gonna make this class with ints.
#ifndef NodeT_h
#define NodeT_h
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

#endif 