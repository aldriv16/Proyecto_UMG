#include <iostream>
using namespace std;

// Función que convierte unidades según la opción seleccionada
void convertirUnidades(int opcion, double valor) {
    double resultado;
    switch (opcion) {
        case 1:
            resultado = valor * 0.621371;
            cout << "Resultado: " << resultado << " millas" << endl;
            break;
        case 2:
            resultado = valor / 0.621371;
            cout << "Resultado: " << resultado << " kilometros" << endl;
            break;
        case 3:
            resultado = valor * 39.3701;
            cout << "Resultado: " << resultado << " pulgadas" << endl;
            break;
        case 4:
            resultado = valor / 39.3701;
            cout << "Resultado: " << resultado << " metros" << endl;
            break;
        case 5:
            resultado = valor * 0.453592;
            cout << "Resultado: " << resultado << " kilos" << endl;
            break;
        case 6:
            resultado = valor / 0.453592;
            cout << "Resultado: " << resultado << " libras" << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
    }
}

int main() {
    double valor;
    int subopcion;

    cout << "\nConversor de Unidades" << endl;
    cout << "1. Kilometros a Millas" << endl;
    cout << "2. Millas a Kilometros" << endl;
    cout << "3. Metros a Pulgadas" << endl;
    cout << "4. Pulgadas a Metros" << endl;
    cout << "5. Libras a Kilos" << endl;
    cout << "6. Kilos a Libras" << endl;
    cout << "Seleccione una opcion: ";
    cin >> subopcion;
    cout << "Ingrese el valor a convertir: ";
    cin >> valor;

    convertirUnidades(subopcion, valor);

    return 0;
}

