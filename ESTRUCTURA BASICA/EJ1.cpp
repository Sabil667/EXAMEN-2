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





};