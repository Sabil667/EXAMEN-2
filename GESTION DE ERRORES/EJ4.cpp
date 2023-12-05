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









};