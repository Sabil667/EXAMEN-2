#include <iostream>
#include <variant>
#include <map>

class Entorno {
public:
    // Método para insertar una nueva configuración en el entorno
    template <typename T>
    void insert(const std::string& clave, const T& valor) {
        auto it = entorno_.find(clave);
        if (it != entorno_.end()) {
            throw std::invalid_argument("La clave ya existe en el entorno.");
        } else {
            entorno_[clave] = valor;
        }
    }

    // Método para obtener una configuración del entorno
    template <typename T>
    T obtenerConfiguracion(const std::string& clave) const {
        auto it = entorno_.find(clave);
        if (it != entorno_.end()) {
            return std::get<T>(it->second); // Configuración encontrada
        } else {
            throw std::out_of_range("La clave no existe en el entorno.");
        }
    }








};