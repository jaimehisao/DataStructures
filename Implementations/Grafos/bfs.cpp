/*
Recorrido de BFS con Matriz de Adjacencias
Jaime Hisao Yesaki Hinojosa A01720044
Estructura de Datos
*/
#include<iostream>
#include<queue>
#include<vector>

#define N 10

using namespace std;

void initMatAdj(bool matAdj[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            matAdj[i][j] = false;
        }
    }
}

void leeMatAdj(bool matAdj[N][N], int e){
    int a, b;
    for(int i = 1; i <= e; i++){
        cin>>a>>b;
        matAdj[a-1][b-1] = matAdj[b-1][a-1] = true;
    }
}

void print(bool matAdj[N][N], int v){
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            cout<<matAdj[i][j]<<" ";
        }
        cout<<endl;
    }
}

void BFS(bool matAdj[N][N], int v){
    queue<int> fila;
    vector<bool> status(v,false);
    int arranque;
    cin>>arranque;
    fila.push(arranque-1);
    status[arranque-1] = true;
    int dato;
    while(!fila.empty()){
        dato = fila.front();
        fila.pop();
        cout<<(dato+1)<<" ";
        for(int j = 0; j < v; j++){
            if(matAdj[dato][j] && !status[j]){
                fila.push(j);
                status[j] = true;
            }
        }
    }
}

int main(){
    bool matAdj[N][N];
    int v, e;
    //v = Cantidad de Vertices (Vertex)
    //e = Cantidad de Arcos (Edges)
    cin>>v>>e;

    initMatAdj(matAdj);
    leeMatAdj(matAdj, e);
    print(matAdj, v);
    //BFS(matAdj,v);


    return 0;
}