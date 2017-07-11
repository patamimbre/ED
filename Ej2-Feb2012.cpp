//Vector Disperso


#include <iostream>
#include <map>

using namespace std;


class VectorDisperso{
    private:
        map<int,string> M;
        string v_def;
    public:
        VectorDisperso(const map<int,string> & mapa, const string & s):M(mapa),v_def(s){}
        string getDefault(){
            return v_def;
        }

        string setDefault(string str){
            for(auto it : M)
                if (it.second == v_def)
                    it.second = str;
        
            v_def = str;
        }

        string getVal(int pos){
            auto it = M.find(pos);
            if (it == M.end())
                return v_def;
            else
                return (*it).second;
        }

        int numNonDefault(){
            return M.size();
        }

        //devuelve valores de una posicion del map
        void datosPosicion(const int & pos, int & key, string & value) const{
            if (pos < M.size()){
                map<int,string>::const_iterator it = next(M.begin(),pos);
                key = (*it).first;
                value = (*it).second;
            }
            else{
                key = -1;
                value = "(empty)";
            }
        }
        
};

int main(){
    map<int, string> mapa;
    mapa [2] = "yoni";
    mapa [5] = "papelas";
    mapa [12] = "cinturones";
    mapa [13] = "mensajero";
    mapa [21] = "comisario";
    string d = "por defecto";

    VectorDisperso v = VectorDisperso(mapa, d);

    cout << "Valor por defecto: " << v.getDefault() << endl;
    
    int key;
    string value;
    cout << "Datos en posiciones DEL MAPA " << endl;
    for (int i = 0; i < v.numNonDefault(); ++i){
        v.datosPosicion(i,key,value);
        cout << "i->" << i << "\t key->" << key << "\t value ->" << value << endl;
    }



    return 0;
}