#include <iostream>
#include <map>
#include <stdexcept>
#include <variant>

class Entorno {
public:
    // Método para insertar un nuevo símbolo en el entorno
    template <typename T>
    void insert(const std::string& clave, const T& valor) {
        auto it = entorno_.find(clave);
        if (it != entorno_.end()) {
            throw std::invalid_argument("La clave ya existe en el entorno.");
        } else {
            entorno_[clave] = valor;
        }
    }

    // Método para buscar un símbolo en el entorno
    template <typename T>
    T lookup(const std::string& clave) const {
        auto it = entorno_.find(clave);
        if (it != entorno_.end()) {
            return std::get<T>(it->second); // Símbolo encontrado
        } else {
            throw std::out_of_range("La clave no existe en el entorno.");
        }
    }

    // Método para eliminar un símbolo del entorno
    void eliminar(const std::string& clave) {
        auto it = entorno_.find(clave);
        if (it != entorno_.end()) {
            entorno_.erase(it);
        } else {
            throw std::out_of_range("No se puede eliminar la clave que no existe en el entorno.");
        }
    }

    // Método para verificar si un símbolo existe en el entorno
    bool existe(const std::string& clave) const {
        return entorno_.find(clave) != entorno_.end();
    }

private:
    std::map<std::string, std::variant<int, double, std::string>> entorno_;
};

int main() {
    Entorno entorno;

    try {
        // Insertar símbolos de diferentes tipos en el entorno
        entorno.insert("variable1", 42);
        entorno.insert("variable2", 3.14);
        entorno.insert("variable3", std::string("Hola"));

        // Buscar símbolos de diferentes tipos en el entorno
        std::cout << "Valor de variable1: " << entorno.lookup<int>("variable1") << std::endl;
        std::cout << "Valor de variable2: " << entorno.lookup<double>("variable2") << std::endl;
        std::cout << "Valor de variable3: " << entorno.lookup<std::string>("variable3") << std::endl;

        // Eliminar un símbolo
        entorno.eliminar("variable2");

        // Verificar si un símbolo existe
        if (entorno.existe("variable2")) {
            std::cout << "variable2 existe en el entorno." << std::endl;
        } else {
            std::cout << "variable2 no existe en el entorno." << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error al insertar: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
