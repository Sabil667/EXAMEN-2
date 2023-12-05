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

    // Método para verificar si una configuración existe en el entorno
    bool existeConfiguracion(const std::string& clave) const {
        return entorno_.find(clave) != entorno_.end();
    }

private:
    std::map<std::string, std::variant<int, double, std::string>> entorno_;
};

// Función para procesar configuraciones del entorno
void procesarConfiguraciones(const Entorno& entorno) {
    try {
        // Obtener y procesar una configuración entera
        int nivelDificultad = entorno.obtenerConfiguracion<int>("nivelDificultad");
        std::cout << "Nivel de dificultad: " << nivelDificultad << std::endl;

        // Obtener y procesar una configuración de punto flotante
        double velocidadPersonaje = entorno.obtenerConfiguracion<double>("velocidadPersonaje");
        std::cout << "Velocidad del personaje: " << velocidadPersonaje << std::endl;
        // Obtener y procesar una configuración de cadena de texto
        std::string nombreJugador = entorno.obtenerConfiguracion<std::string>("nombreJugador");
        std::cout << "Nombre del jugador: " << nombreJugador << std::endl;

        // Verificar la existencia de una configuración
        if (entorno.existeConfiguracion("tiempoLimite")) {
            int tiempoLimite = entorno.obtenerConfiguracion<int>("tiempoLimite");
            std::cout << "Tiempo límite: " << tiempoLimite << " segundos" << std::endl;
        } else {
            std::cout << "No se ha configurado un tiempo límite." << std::endl;
        }
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
int main() {
    // Crear un entorno de juego
    Entorno entorno;

    // Configurar opciones de juego
    entorno.insert("nivelDificultad", 2);
    entorno.insert("velocidadPersonaje", 5.0);
    entorno.insert("nombreJugador", std::string("Jugador1"));

    // Procesar configuraciones
    procesarConfiguraciones(entorno);


}










