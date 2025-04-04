#include <iostream>
#include <conio.h>

using namespace std;

// Declaración de funciones (prototipos)
void imprimirTriangulo(int filas);
void imprimirCuadro(int lado);
void imprimirCirculo(int radio);

void imprimirTriangulo(int filas) {
    for (int i = 0; i < filas; i++) {
        // Espacios antes del asterisco
        for (int j = 0; j < filas - i - 1; j++) {
            cout << " ";
        }
        // Asteriscos para el triángulo
        for (int j = 0; j < i * 2 + 1; j++) {
            cout << "*";
        }
        cout << endl; // Salto de línea después de cada fila
    }
}

void imprimirCuadro(int lado) {
    for (int i = 1; i <= lado; i++) {
        for (int j = 1; j <= lado; j++) {
            cout << "*";
        }
        cout << endl; // Salto de línea después de cada fila
    }
}

void imprimirCirculo(int radio) {
    for (int i = 0; i <= 2 * radio; i++) {
        for (int j = 0; j <= 2 * radio; j++) {
            // Verificamos si el punto (i, j) está dentro del círculo
            if ((i - radio) * (i - radio) + (j - radio) * (j - radio) <= radio * radio) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl; // Salto de línea después de cada fila
    }
}

int main() {
    int opcion;
    int filasTriangulo, ladoCuadrado, radioCirculo;
    char continuar;

    do {
        // Menú de selección
        cout << "Que figura desea realizar?" << endl;
        cout << "1. Triangulo" << endl;
        cout << "2. Cuadrado" << endl;
        cout << "3. Circulo" << endl;
        cout << "Ingrese el numero de la figura (1-3): ";
        cin >> opcion;

        // Acciones según la opción seleccionada
        switch(opcion) {
            case 1:
                cout << "Ingrese el numero de filas para el triangulo: ";
                cin >> filasTriangulo;
                cout << "\nTriangulo: \n";
                imprimirTriangulo(filasTriangulo);
                break;

            case 2:
                cout << "Ingrese el lado del cuadrado: ";
                cin >> ladoCuadrado;
                cout << "\nCuadrado: \n";
                imprimirCuadro(ladoCuadrado);
                break;

            case 3:
                cout << "Ingrese el radio del círculo: ";
                cin >> radioCirculo;
                cout << "\nCirculo: \n";
                imprimirCirculo(radioCirculo);
                break;

            default:
                cout << "Opcion no valida. Por favor ingrese un numero entre 1 y 3." << endl;
        }

        // Preguntar si desea realizar otra figura o salir
        cout << "\nDesea realizar otra figura? (S/N): ";
        cin >> continuar;

    } while(continuar == 'S' || continuar == 's'); // Repite si el usuario ingresa 'S' o 's'

    cout << "Gracias por usar el programa" << endl;

    getch(); 
    return 0;
}

