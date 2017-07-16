#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template <typename T>
void print(stack<T> st){
    while (!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

template<typename T>
void push(vector<T> &v, stack<T> pila, T elem){
    auto it = v.begin();
    int tam_pila = pila.size()-1;
    bool encontrado = false;
    T tope = pila.top();
    T base;

    while(pila.size() > 1){
        pila.pop();
    }

    base = pila.top();

    while(!encontrado && it != v.end()){
        if (*it == base && *(next(it,tam_pila)) == tope ){
            it = (next(it,tam_pila));
            encontrado = true;
        }
        else {
            ++it;
        }
    }

    if (it != v.end()){
        cout << "\nAntiguo tope: " << *it << "\tNuevo tope: " << elem << endl;
        it = v.insert(it+1,elem);

    }   
    else{
        cout << "\nLa pila introducida no existe en el contenedor" << endl;
    }
}

template<typename T>
typename vector<T>::iterator findStack(const vector<T> &v, stack<T> & pila){
    
}


template<typename T>
void pop(vector<T> &v, stack<T> pila){
    auto it = v.begin();
    int tam_pila = pila.size()-1;
    bool encontrado = false;
    T tope = pila.top();
    T base;

    while(pila.size() > 1){
        pila.pop();
    }

    base = pila.top();

    while(!encontrado && it != v.end()){
        if (*it == base && *(next(it,tam_pila)) == tope ){
            it = (next(it,tam_pila));
            encontrado = true;
        }
        else {
            ++it;
        }
    }

    if (it != v.end()){
        cout << "\nAntiguo tope: " << *it << "\tNuevo tope: " << *(it-1) << endl;
        it = v.erase(it);

    }   
    else{
        cout << "\nLa pila introducida no existe en el contenedor" << endl;
    }
}



int main(){

    stack<int> st1, st2, st3;
    vector<int> contenedor;

    for(int i = 1; i < 5; ++i){
        st1.push(i);
        contenedor.push_back(i);
    }


    for(int i = 1; i < 12; i*=2){
        st2.push(i);
        contenedor.push_back(i);
    }


    for(int i = 3; i < 25; i*=3){
        st3.push(i);
        contenedor.push_back(i);
    }

    

    cout << "Pila 1 -> "; print(st1);
    cout << "Pila 2 -> "; print(st2);
    cout << "Pila 3 -> "; print(st3);

    cout << "Contenedor -> ";
    for (auto it: contenedor){
        cout << it << " ";
    }
    cout << endl;

    push(contenedor, st2, 6);

    cout << "Contenedor op. push (elem 6, pila 2) -> ";
    for (auto it: contenedor){
        cout << it << " ";
    }
    cout << endl;

    pop(contenedor,st1);
    cout << "Contenedor op. pull (pila 1) -> ";
    for (auto it: contenedor){
        cout << it << " ";
    }
    cout << endl << endl;


    return 0;
}