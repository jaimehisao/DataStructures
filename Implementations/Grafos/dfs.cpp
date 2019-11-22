/*
Recorrido de DFS (Profundidad) con Lista de Adjacencias
Jaime Hisao Yesaki Hinojosa A01720044
Estructura de Datos
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void leeListaAdj(vector<vector<int> > &listaAdj, int edges){
    int a, b;
    for(int i = 1; i<=edges; i++){
        cin>>a>>b;
        listaAdj[a-1].push_back(b-1);
        listaAdj[b-1].push_back(a-1);
    }
}

void printListaAdj(vector<vector<int> > &listaAdj){
    for(int i = 0; i<listaAdj.size(); i++){
        cout<<(i+1)<<" ";
        for(int j = 0; j<listaAdj[i].size();j++){
            cout<<" - "<<(listaAdj[i][j]+1);
        }
        cout<<endl;
    }
}

void DFS(vector<vector<int> > &listaAdj){
    stack<int> pila;
    int arranque;
    cin>>arranque;
    pila.push(arranque-1);
    int dato;
    vector<bool> status(listaAdj.size(), false);
    int cantVisitados = 0;
    while(!pila.empty() && cantVisitados != listaAdj.size()){
        dato = pila.top();
        pila.pop();
        if(!status[dato]){
            cout<<(dato+1)<<" ";
            status[dato] = true;
            cantVisitados++;
            for(int j = listaAdj[dato].size()-1; j>=0; j--){
                if(!status[listaAdj[dato][j]]){
                    pila.push(listaAdj[dato][j]);
                }
            }
        }
    }
    cout<<endl;
}

int main(){
    int vertices, edges;
    cin>>vertices>>edges;
    vector<vector<int> > listaAdj(vertices);
    leeListaAdj(listaAdj, edges);
    printListaAdj(listaAdj);
    DFS(listaAdj);
    return 0;
}
