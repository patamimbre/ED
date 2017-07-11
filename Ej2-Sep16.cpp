#include <iostream>
#include <map>
#include <vector>

using namespace std;

template<typename T>
void Procesa (const vector<T> &entrada, map<T, int> & mapa){
    
    for (auto it = entrada.begin(); it != entrada.end(); ++it) {
        
        if (mapa.count (*it) == 0){
            mapa[*it] = 1;
        }
        else {
            mapa[*it] = mapa[*it] + 1;
        }
    }
}

template<typename T>
T getVal (int pos, const map<T,int> &mapa){
    int count = -1;

    for(auto it:mapa){
        if (count + it.second < pos){
            count += it.second;
        }
        else
            return it.first;
    }

    return -1;

}

int main(){
    map<int,int> mapa;
    vector<int> v;
    for (int i=0; i < 3; ++i){
        v.push_back(1);
    }

    for (int i=0; i < 4; ++i){
        v.push_back(3);
    }

    v.push_back(5);
    v.push_back(5);
    v.push_back(6);

    for (int i=0; i < 6; ++i){
        v.push_back(8);
    }

    // v = {1,1,1,3,3,3,3,5,5,6,8,8,8,8,8,8}
    
    Procesa(v,mapa);

    for (auto it : mapa){
        cout << "valor " << it.first << " -> " << it.second << " elementos" << endl;
    }

    //p(3) = 3  p(7) = 5
    for (int i = 0; i < v.size(); i++)
        cout << "En la posicion " << i << " -> " << getVal(i,mapa) << endl;

}