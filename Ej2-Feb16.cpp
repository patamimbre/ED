#include <iostream>
#include <list>

using namespace std;

//La paso por valor, asi puedo modificarla
bool sumaIgual (list<list<int> > L){

    bool correcto = true;
    int res = 0, res_local = 0;

    //horizontal
    for (auto it_ex = L.begin(); it_ex != L.end(); ++it_ex){
        res_local = 0;  
        for (auto it_in = (*it_ex).begin(); it_in != (*it_ex).end(); ++it_in){
            //si es la primera lista guardo su valor para comparar
            if (it_ex == L.begin()){
                res += *it_in;
            }
            res_local += *it_in;
        }

        if (res != res_local){
            return false;
        }
    }

    //Vertical
    int count = 0;

    while (count < L.size()){
        auto it_ex = L.begin();
        res_local = 0;
        for (; it_ex != L.end(); ++it_ex){
            res_local += (*it_ex).front();
            (*it_ex).pop_front();
        }

        if ( res != res_local){
            return false;
        }

        count++;
    }

    return true;
}

int main(){
    list<list<int> > l_externa;
    list<int> l_interna;

    l_interna.push_back(0);
    l_interna.push_back(1);
    l_interna.push_back(1);
    l_interna.push_back(1);
    l_externa.push_back(l_interna);
    
    l_interna.clear();
    l_interna.push_back(2);
    l_interna.push_back(1);
    l_interna.push_back(0);
    l_interna.push_back(0);
    l_externa.push_back(l_interna);

    l_interna.clear();
    l_interna.push_back(1);
    l_interna.push_back(0);
    l_interna.push_back(2);
    l_interna.push_back(0);
    l_externa.push_back(l_interna);

    l_interna.clear();
    l_interna.push_back(0);
    l_interna.push_back(1);
    l_interna.push_back(0);
    l_interna.push_back(2);
    l_externa.push_back(l_interna);

    cout << "      :::PRINT:::" << endl;
    for (auto it_ex = l_externa.begin(); it_ex != l_externa.end(); ++it_ex){
        cout << "\t";
        for (auto it_in = (*it_ex).begin(); it_in != (*it_ex).end(); ++it_in){
            cout << *it_in << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "¿Mismo resultado en horizontal y vertical? ";
    sumaIgual(l_externa)? cout << "Si" : cout << "No";
    cout << endl << endl;
    return 0;
}