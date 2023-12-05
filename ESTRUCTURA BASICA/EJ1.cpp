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





};