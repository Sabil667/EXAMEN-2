#include <iostream>
#include <string>
#include <map>

class Environment {
public:
    //Constructor
    Environment() {}

    //Destructor
    ~Environment() {}

    //Forma para agregar simbolo a una tabla de simbolos.
    void addSymbol(const std::string& name, int value) {
        symbols[name] = value;
    }

    //Forma para obtener el valor de un simbolo de la tabla de simbolos.
    int getSymbolValue(const std::string& name) const {
        auto it = symbols.find(name);
        if (it != symbols.end()) {
            return it->second;
        } else {
            std::cerr << "Error: Symbol '" << name << "' not found." << std::endl;
            // Puedes manejar el error de otra manera, esto es solo un ejemplo
            return 0; // Valor predeterminado en caso de error
        }
    }

private:
std::map<std::string, int> symbols; // Tabla de símbolos
};

//Ejemplo
int main(){

    Environment env;
    //Agregar simbolos a la tabla
    env.addSymbol("g", 40);
    env.addSymbol("h", 60);

    //Obtener valores de la tabla
    std::cout << "Value of g: " << env.getSymbolValue("g") << std::endl;
    std::cout << "Value of h: " << env.getSymbolValue("h") << std::endl;
    std::cout << "Value of i: " << env.getSymbolValue("i") << std::endl; // Debería imprimir un mensaje de error





};