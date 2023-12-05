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






};