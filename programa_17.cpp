#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	
    // numeros aleatorios
    std::srand(std::time(0));

    int numeroSecreto = std::rand() % 100 + 1;
    int intento;
    int intentos = 0;

    std::cout << "Bienvenido al juego de adivinanza de numeros!" << std::endl;
    std::cout << "Estoy pensando en un numero entre 1 y 100. Adivinalo" << std::endl;

    do {
        std::cout << "Introduce tu intento: ";
        std::cin >> intento;

        intentos++;

        if (intento < numeroSecreto) {
            std::cout << "Demasiado bajo. Intenta de nuevo." << std::endl;
        } else if (intento > numeroSecreto) {
            std::cout << "Demasiado alto. Intenta de nuevo." << std::endl;
        } else {
            std::cout << "¡Felicidades! Adivinaste el numero en " << intentos << " intentos." << std::endl;
        }

    } while (intento != numeroSecreto);

    return 0;
}

