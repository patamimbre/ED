#include <iostream>
#include <list>

using namespace std;


//La lista original no es modificada ya que el paso es
//por valor (solo se modifica en el contexto de la funcion)
void agrupa (list<int> in, list<list<int> > & out){
    in.sort();

    list<int> sublista;
    auto it = in.begin();
    
    sublista.push_back(*it);

    while(++it != in.end()){
        if(sublista.front() == *it){
            sublista.push_back(*it);
        }
        else{
            out.push_back(sublista);
            sublista.clear();
            sublista.push_back(*it);
        }
    }
    out.push_back(sublista);
}


int main(){
    list<int> entrada;
    list<list<int> > salida;

    entrada.push_back(1);
    entrada.push_back(3);
    entrada.push_back(4);
    entrada.push_back(5);
    entrada.push_back(6);
    entrada.push_back(3);
    entrada.push_back(2);
    entrada.push_back(1);
    entrada.push_back(4);
    entrada.push_back(5);
    entrada.push_back(5);
    entrada.push_back(1);
    entrada.push_back(1);
    entrada.push_back(7);
    

    cout << "\n      :::ORIGINAL:::" << endl << "{ ";
    for (auto it : entrada)
        cout << it << " " ;
    cout << "}" << endl;

    agrupa(entrada, salida);

    cout << "\n      :::AGRUPADA:::" << endl;
    for (auto it_ex = salida.begin(); it_ex != salida.end(); ++it_ex){
        cout << "{ ";
        for (auto it_in = (*it_ex).begin(); it_in != (*it_ex).end(); ++it_in){
            cout << *it_in << " ";
        }
        cout << "} ";
    }
    cout << endl << endl;


    return 0;
}