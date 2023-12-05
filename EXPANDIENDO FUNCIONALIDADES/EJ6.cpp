#include <iostream>
#include <map>
#include <stdexcept>

class Entorno {
public:
    //Insertar nuevo símbolo en el entorno
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

    //Eliminar un símbolo del entorno
    void eliminar(const std::string& clave) {
        auto it = entorno_.find(clave);
        if (it != entorno_.end()) {
            entorno_.erase(it);
        } else {
            throw std::out_of_range("No se puede eliminar la clave que no existe en el entorno.");
        }
    }





};