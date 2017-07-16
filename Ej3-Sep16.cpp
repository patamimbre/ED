#include <iostream>
#include <list>

using namespace std;

template <typename T>
void duplicar(const list<T> & inicial, list<T> & final){
    
    auto it_begin = inicial.begin();
    auto it_end = next(inicial.end(),-1);

    while (it_begin != inicial.end()){
        final.push_back(*it_begin);
        final.push_back(*it_end);
        ++it_begin;
        --it_end;
    }

}

int main(){

    list<int> l_ini, l_fin_1, l_fin_2;

    cout << "Original -> ";
    for(int i=1; i < 6; ++i){
        l_ini.push_back(i);
        cout << i << " ";
    }

    duplicar(l_ini, l_fin_1);

    cout << "\nDuplicada método 1-> ";
    for (auto it: l_fin_1){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}