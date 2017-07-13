#include <iostream>
#include <cassert>
#include <map>
#include <set>

using namespace std;

typedef map<string, set<string> > diccionario;

//Ernesto Serrano (erseco) implementa una versión completa del ejercicio
//https://github.com/erseco/ugr_estructuras_datos

class Traductor{
    private:
        diccionario dic;
    public:
        Traductor(diccionario d):dic(d){}
        void insertar(const string &palabra, const set<string> &traducciones){
            if (palabra != "" && traducciones.size() != 0)
                dic[palabra] = traducciones;
        }

        set<string> consultar(const string & palabra) const {
            return (dic.find(palabra))->second;
        }

        void listaDiccionario(){
            cout << "\n:::TRADUCCIONES GUARDADAS:::\n";
            for(auto it1 : dic){
                cout << it1.first;
                for (auto it2: it1.second){
                    cout << "\t···" << it2 << endl;
                }
                cout << endl;
            }
        }

        //El iterador muestra todas en el idioma origen
        class ConstIterator{
            private:
                diccionario::const_iterator it;

            public:
                ConstIterator(){}
                ConstIterator & operator ++ (){
                    ++it;
                    return *this;
                }
                ConstIterator & operator -- (){
                    --it;
                    return *this;
                }
                const pair<const string, set<string> > & operator * (){
                    return *it;
                }

                bool operator == (const ConstIterator &it2){
                    return it == it2.it;    
                }

                bool operator != (const ConstIterator &it2){
                    return it != it2.it;
                }

                friend class Traductor;
        };

        ConstIterator begin() const {
            ConstIterator i;
            i.it = dic.begin();
            return i;
        }

        ConstIterator end() const{
            ConstIterator i;
            i.it = dic.end();
            return i;
        }

        ConstIterator find(const string & palabra){
            ConstIterator i;
            i.it = dic.find(palabra);
            return i;
        }


};


int main(){

    diccionario dic;
    set<string> traduc;

    traduc.insert("eye");
    traduc.insert("care");
    traduc.insert("keyhole");
    dic["ojo"] = traduc;

    traduc.clear();
    traduc.insert("key");
    traduc.insert("wrench");
    dic["llave"] = traduc;

    traduc.clear();
    traduc.insert("word");
    traduc.insert("promise");
    dic["palabra"] = traduc;

    Traductor traductor = Traductor(dic);

    cout << "\n(Listando con el método de la clase)";
    traductor.listaDiccionario();

    Traductor::ConstIterator t_it;
    cout << "\n(Listando con iteradores)";
    cout << "\n:::TRADUCCIONES GUARDADAS:::\n";
    for (t_it = traductor.begin(); t_it != traductor.end(); ++t_it){
        cout << (*t_it).first ;
        for (auto it2: (*t_it).second){
            cout << "\t···" << it2 << endl;
        }
        cout << endl;
    }

    return 0;
}