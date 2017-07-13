#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
//random
#include<stdlib.h>
#include<time.h>
//random_shuffle(it first, it last)
#include <algorithm>    

using namespace std;

void barajaVector(vector<int> &v){
    srand(unsigned(time(0)));
    random_shuffle(v.begin(),v.end());
}

void barajaLista(list<int> &l){
    srand(unsigned(time(0)));
    unordered_set<int> baraja;

    while (baraja.size() < l.size()){
        baraja.insert(1+rand()%(41-1));
    }

    l.clear();
    for (auto it: baraja){
        l.push_back(it);
    }

}

void barajaPila(stack<int> &s){
    srand(unsigned(time(0)));
    stack<int> s_aux;

    unordered_set<int> baraja;
    while (baraja.size() < s.size()){
        baraja.insert(1+rand()%(41-1));
    }

    for (auto it: baraja){
        s_aux.push(it);
    }
    s=s_aux;
}

void barajaCola(queue<int> & q){
    srand(unsigned(time(0)));
    queue<int> q_aux;

    unordered_set<int> baraja;
    while (baraja.size() < q.size()){
        baraja.insert(1+rand()%(41-1));
    }

    for (auto it: baraja){
        q_aux.push(it);
    }
    q=q_aux;
}



int main(){

    //numeros entre 1 y 40
    //int num=1+rand()%(41-1);

    list<int> listaCartas;
    vector<int> vectorCartas;
    queue<int> colaCartas;
    stack<int> pilaCartas;

    //Baraja ordenada
    for(int i = 1; i <= 40; i++){
        listaCartas.push_back(i);
        vectorCartas.push_back(i);
        colaCartas.push(i);
        pilaCartas.push(i);
    }

    barajaLista(listaCartas);
    cout << "\nLista -> ";
    for(auto it:listaCartas)
        cout << it << " ";

    barajaVector(vectorCartas);
    cout << "\n\nVector -> ";
    for(auto it:vectorCartas)
        cout << it << " ";

    barajaCola(colaCartas);
    cout << "\n\nCola -> ";
    queue<int> colaAux = colaCartas;
    while(!colaAux.empty()){
        cout << colaAux.front() << " ";
        colaAux.pop();
    }

    barajaPila(pilaCartas);
    cout << "\n\nPila -> ";
    stack<int> pilaAux = pilaCartas;
    while(!pilaAux.empty()){
        cout << pilaAux.top() << " ";
        pilaAux.pop();
    }


    cout << "\n\n";







    return 0;
}