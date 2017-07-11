#include <list>
#include <stack>
#include <iostream>

using namespace std;

typedef list<stack<int> > miLista;

void print(miLista L, string title){
    cout << "      :::" << title << ":::" << endl;
    for (auto it = L.begin(); it != L.end(); ++it){
        cout << "     -> ";
        while (!(*it).empty()){
            cout << (*it).top() << " ";
            (*it).pop();
        }
        cout << endl;
    }
}

void Borrar(miLista & L, const int & elem){

    for (auto it = L.begin(); it != L.end(); ++it){
        if ( (*it).top() == elem){
            (*it).pop();
        }
        if ( (*it).size() == 0 ){
            it = L.erase(it);
        }
    }

    //expresión lambda
    L.sort([](const stack<int> &a, const stack<int> &b) 
        {return a.top() < b.top();});
}

int main(){

    miLista lst;
    stack<int> st;
    st.push(1);
    st.push(9);
    st.push(2);
    lst.push_back(st);
    st=stack<int>();
    
    st.push(0);
    st.push(1);
    st.push(2);
    lst.push_back(st);
    st=stack<int>();

    st.push(2);
    lst.push_back(st);
    st=stack<int>();

    st.push(7);
    st.push(10);
    st.push(9);
    st.push(3);
    lst.push_back(st);
    st=stack<int>();

    st.push(2);
    st.push(4);
    lst.push_back(st);
    st=stack<int>();

    st.push(2);
    st.push(8);
    lst.push_back(st);
    st=stack<int>();

    print(lst, "ORIGINAL");
    Borrar(lst,2);
    print(lst, "MODIFICADA");






}