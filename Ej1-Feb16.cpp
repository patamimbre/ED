#include <map>
#include <iostream>
#include <stdexcept>


using namespace std;

//Version de ejemplo, no refleja dirección

struct Contacto {
    string nombre;
    int num_tel;
    Contacto(){}
    Contacto(string nom, int t): nombre(nom), num_tel(t){}
};

class Agenda{
    private:
        map<string,Contacto> mapNombre;
        map<int, Contacto> mapTel;
    public:
        bool Inserta(const Contacto & p){
            mapNombre[p.nombre] = p;
            mapTel[p.num_tel] = p;
        }

        bool EliminaContacto(const string & nombre){
            auto it = mapNombre.find(nombre);
            int numero;
            
            if ( it != mapNombre.end()){
                Contacto c = (*it).second;
                numero = c.num_tel;
                mapNombre.erase(it);
                auto it = mapTel.find(numero);
                if ( it != mapTel.end()){
                    mapTel.erase(it);
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        bool EliminaContacto(const int & telefono){
            auto it = mapTel.find(telefono);
           
            if ( it != mapTel.end()){
                Contacto c = (*it).second;
                string nombre = c.nombre;
                mapTel.erase(it);
                auto it = mapNombre.find(nombre);
                if ( it != mapNombre.end()){
                    mapNombre.erase(it);
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        

        Contacto buscaContacto(const string & nombre) const{
            auto it = mapNombre.find(nombre);

            if (it != mapNombre.end())
                return (*it).second;
            else 
                throw invalid_argument("No existe el nombre introducido");

        }
        Contacto buscaContacto(const int & telefono) const{
            auto it = mapTel.find(telefono);

            if (it != mapTel.end())
                return (*it).second;
            else
                throw invalid_argument ("No existe el telefono introducido");
            
        }

        void listaContactos(){
            for( auto it : mapNombre){
                cout << it.first << " -> " << it.second.num_tel << endl;
            }
        }

};

int main(){

    Agenda agenda = Agenda();
    string nombre; 
    int telefono;

    cout << "Añadir a la agenda" << endl;
    do{
        cout << "Nombre: ";
        cin >> nombre;

        if (nombre != "FIN"){
            
            cout << "Telefono: ";
            cin >> telefono;
            
            agenda.Inserta(Contacto(nombre,telefono));
            cout << "Contacto añadido correctamente" << endl;
        }
    } while (nombre != "FIN");

    cout << "\n:::::::::::::::::::::::::::::::::::::\n";
    agenda.listaContactos();

    /*
    agenda.EliminaContacto(666666666);
    agenda.EliminaContacto("Rafa");

    cout << "\n:::::::::::::::::::::::::::::::::::::\n";
    agenda.listaContactos();

    cout << "\n:::::::::::::::::::::::::::::::::::::\n";
    
    cout << "Busqueda:" << endl;
    Contacto c = agenda.buscaContacto("German");
    cout << c.nombre << " -> " << c.num_tel << endl;
    c = agenda.buscaContacto(999999999);
    cout << c.nombre << " -> " << c.num_tel << endl;
    */

    return 0;
}



