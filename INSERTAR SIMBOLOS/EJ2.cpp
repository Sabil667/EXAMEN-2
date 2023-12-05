#include <iostream>
#include <map>

class Entorno {
public:
    //Insertar un nuevo símbolo en el entorno
    void insert(const std::string& clave, int valor) {
        entorno_[clave] = valor;
    }

    //Imprimir el entorno
    void imprimirEntorno() const {
        for (const auto& par : entorno_) {
            std::cout << par.first << ": " << par.second << std::endl;
        }
    }

private:
    std::map<std::string, int> entorno_;
};

int main(){
    Entorno entorno;

    //Insertar simbolos en el entorno
    entorno.insert("variable1", 23);
    entorno.insert("variable2", 7);
    entorno.insert("variable3", 10);

    //Imprimir el entorno
    std::cout << "Entorno inicial:" << std::endl;
    entorno.imprimirEntorno();

//Insertar un nuevo simbolo sin conflictos
    entorno.insert("nuevaVariable", 8);

    //Imprimir el entorno después de la inserción
    std::cout << "\nEntorno despues de la insercion:" << std::endl;
    entorno.imprimirEntorno();

    return 0;






};