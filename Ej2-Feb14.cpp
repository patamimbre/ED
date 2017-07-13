#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

multiset<int> multi_interseccion(const multiset<int> & m1, const multiset<int> & m2){
    multiset<int> res;

    int min_apariciones = 0;
    int val_actual = 0;
    multiset<int>::const_iterator it = m1.begin();

    
    while (it != m1.end()){
        val_actual = (*it);
        min_apariciones = m1.count(val_actual);
        it = next(it,min_apariciones);
        min_apariciones = min(min_apariciones, (int)m2.count(val_actual));
        
        for(int i=0; i < min_apariciones; ++i){
            res.insert(val_actual);
        }
    }

    return res;

}

void print(const multiset<int> & m1, const multiset<int> & m2, const multiset<int> & res){
        cout << "Conjunto 1: { ";
    for (auto it : m1){
        cout << it << " ";
    }
    cout << "}\n";

    cout << "Conjunto 2: { ";
    for (auto it : m2){
        cout << it << " ";
    }
    cout << "}\n";

    cout << "Multi intersección: { ";
    for (auto it : res){
        cout << it << " ";
    }
    cout << "}\n";
}


int main(){
    
    multiset<int> m1, m2, res;

    m1.insert(2);
    m1.insert(2);
    m1.insert(3);
    m1.insert(3);

    m2.insert(1);
    m2.insert(2);
    m2.insert(3);
    m2.insert(3);
    m2.insert(3);
    m2.insert(4);

    res = multi_interseccion(m1,m2);

    cout << "\n:::EJEMPLO 1:::\n";
    print(m1,m2,res);
    cout << endl;

    m1.clear(); m2.clear(); res.clear();

    m1.insert(2);
    m1.insert(2);
    m1.insert(2);
    m1.insert(3);
    m1.insert(3);

    m2.insert(1);
    m2.insert(2);
    m2.insert(2);
    m2.insert(2);
    m2.insert(2);
    m2.insert(3);
    m2.insert(3);
    m2.insert(3);
    m2.insert(4);

    res = multi_interseccion(m1,m2);

    cout << "\n:::EJEMPLO 2:::\n";
    print(m1,m2,res);
    cout << endl;




    return 0;
}