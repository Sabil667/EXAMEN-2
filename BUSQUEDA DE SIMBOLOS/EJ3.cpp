#include <iostream>
#include <map>
#include <optional>

class Entorno {
public:
    //Insertar un nuevo símbolo en el entorno
    void insert(const std::string& clave, int valor) {
        entorno_[clave] = valor;
    }

    //Buscar un símbolo en el entorno
    std::optional<int> lookup(const std::string& clave) const {
        auto it = entorno_.find(clave);
        if (it != entorno_.end()) {
            return it->second; // Símbolo encontrado
        } else {
            return std::nullopt; // Símbolo no encontrado
        }
    }

private:
    std::map<std::string, int> entorno_;
};

int main(){
    Entorno entorno;

    //Insertar símbolos en el entorno
    entorno.insert("variable1", 13);
    entorno.insert("variable2", 7);
    entorno.insert("variable3", 10);

    //Buscar símbolos en el entorno
    std::cout << "Valor de variable2: " << entorno.lookup("variable2").value_or(-1) << std::endl;








};