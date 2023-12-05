#include <iostream>
#include <map>
#include <stdexcept>

class Entorno {
public:
    //Insertar un nuevo símbolo en el entorno
    void insert(const std::string& clave, int valor) {
        auto it = entorno_.find(clave);
        if (it != entorno_.end()) {
            throw std::invalid_argument("La clave ya existe en el entorno.");
        } else {
            entorno_[clave] = valor;
        }
    }

    //Buscar un símbolo en el entorno
    int lookup(const std::string& clave) const {
        auto it = entorno_.find(clave);
        if (it != entorno_.end()) {
            return it->second; // Símbolo encontrado
        } else {
            throw std::out_of_range("La clave no existe en el entorno.");
        }
    }

private:
    std::map<std::string, int> entorno_;
};

int main(){
    Entorno entorno;

    try{
        //Insertar símbolos en el entorno
        entorno.insert("variable1", 12);
        entorno.insert("variable2", 9);
        entorno.insert("variable3", 8);

        //Intentar insertar un símbolo ya existente
        entorno.insert("variable1", 42);
    }catch(const std::invalid_argument& e){
        std::cerr << "Error al insertar: " << e.what() << std::endl;
    }

    try{
        //Buscar símbolos en el entorno
        std::cout << "Valor de variable2: " << entorno.lookup("variable2") << std::endl;

        //Intentar buscar un símbolo que no existe

        std::cout << "Valor de noExiste: " << entorno.lookup("noExiste") << std::endl;



    }







};