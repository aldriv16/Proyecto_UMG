#include <iostream>
#include <algorithm>
#include <cctype>
#include <limits>

// Función para limpiar la cadena eliminando caracteres no alfanuméricos y convirtiendo a minúsculas
std::string limpiarCadena(const std::string& str) {
    std::string limpio;
    for (char c : str) {
        if (std::isalnum(static_cast<unsigned char>(c))) {
            limpio += std::tolower(static_cast<unsigned char>(c));
        }
    }
    return limpio;
}

// Función para verificar si la cadena es un palíndromo
bool esPalindromo(const std::string& str) {
    std::string limpio = limpiarCadena(str);
    if (limpio.empty()) {
        return false; // Cadena vacía no se considera palíndromo
    }
    std::string reverso = limpio;
    std::reverse(reverso.begin(), reverso.end());
    return limpio == reverso;
}

int main() {
    char opcion;
    
    do {
        std::string entrada;
        std::cout << "\nIngrese una palabra, frase o numero: ";
        std::getline(std::cin, entrada);
        
        // Verificar si la entrada está vacía
        if (entrada.empty()) {
            std::cout << "Error: No se ingreso ningun texto." << std::endl;
            continue;
        }
        
        // Verificar si la entrada limpia está vacía (solo caracteres no alfanuméricos)
        std::string limpio = limpiarCadena(entrada);
        if (limpio.empty()) {
            std::cout << "Error: La entrada no contiene caracteres alfanumericos validos." << std::endl;
            continue;
        }
        
        if (esPalindromo(entrada)) {
            std::cout << "\n\"" << entrada << "\" ES un palindromo." << std::endl;
        } else {
            std::cout << "\n\"" << entrada << "\" NO es un palindromo." << std::endl;
        }
        
        std::cout << "\nDesea verificar otro palindromo? (s/n): ";
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    } while (std::tolower(opcion) == 's');
    
    std::cout << "\nPresione Enter para salir...";
    std::cin.ignore();
    
    return 0;
}
