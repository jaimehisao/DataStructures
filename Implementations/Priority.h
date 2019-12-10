 /*
Priority.h - Implementacion de una Fila Priorizada - Heap
Jaime Hisao Yesaki H A01720044
Estructura de Datos
*/
#include <vector>

using namespace std;

class Priority{
    public:
    Priority();
    Priority(bool);
    void push(int);
    void pop();
    int top();
    int size();
    bool empty();
    private:
    private:
    void moveUp(int);
    void moveDown(int);
    bool compare(int, int);
    bool priority;
    vector<int> pV;
};

//Constructors//
Priority::Priority(){
    //Prioridad Mayor
    this->priority = true;
    pV.push_back(0);
}

Priority::Priority(bool whichPriority){
    //Prioridad Escogida por el usuario
    this->priority = whichPriority;
    pV.push_back(0);
}

void Priority::push(int val){
    //Insert the int value in the vector
    pV.push_back(val);
    moveUp(size());
    //Correct the order of the vector in case that is incorrect
}

void Priority::pop(){
    if(!pV.empty()){
        pV[0] = pV.back();
        pV.pop_back();
        moveDown(0);
    }

}

//Returns the value with the highest priority in the Heap.
int Priority::top(){
    return pV.at(0);
}

//Returns the size of the vector (Heap)
int Priority::size(){
    return pV.size();
}

//Returns a boolean value depending if the vector (Heap) is empty or not
bool Priority::empty(){
    return pV.size() == 0;
}

//Helper Functions
void Priority::moveUp(int num){
    if(priority){
        if(num > pV[(num-1)/2] && num > pV[num]){
            swap(pV[num], pV[(num-1)/2]);
            moveUp((num-1)/2);
    }
    }else{
        if(num > pV[num]){
            swap(pV[num], pV[(num-1)/2]);
            moveUp((num-1)/2);
    }
    }
}

void Priority::moveDown(int num){
    int lChild = num*2+1;
    int rChild = num*2+2;
    int lgst = num;

    if(priority){
        if(lChild < pV.size() && pV[lChild] < pV[num]){
            lgst = lChild;
        }

         if(lChild < pV.size() && pV[rChild] < pV[lgst]){
            lgst = rChild;
        }

        if(lgst != num){
            swap(pV[num], pV[lgst]);
            moveDown(num);
        }
    }else{
        if(lChild < pV.size() && pV[lChild] > pV[num]){
            lgst = lChild;
        }

         if(lChild < pV.size() && pV[rChild] > pV[lgst]){
            lgst = rChild;
        }

        if(lgst != num){
            swap(pV[num], pV[lgst]);
            moveDown(num);
        }
    }




}



