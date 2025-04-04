#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>

using namespace std;

void mostrarMenu() {
    cout << "\n=== MENU PRINCIPAL ===" << endl;
    cout << "1. Verificador de palindromos" << endl;
    cout << "2. Conversor de numeros a letras (entero)" << endl;
    cout << "3. Conversor de numeros a letras (con decimales)" << endl;
    cout << "4. Metodo de Horner para polinomios (Programa Libre)" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    int opcion;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida. Intente nuevamente." << endl;
            continue;
        }
        
        switch(opcion) {
            case 1:
                system("g++ -o palindromo Programa_4.cpp && palindromo.exe");
                break;
            case 2:
                system("g++ -o conversor_entero Programa_6.cpp && conversor_entero.exe");
                break;
            case 3:
                system("g++ -o conversor_decimal Programa_7.cpp && conversor_decimal.exe");
                break;
            case 4:
                system("g++ -o horner Programa_20_libre.cpp && horner.exe");
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
        }
        
    } while (opcion != 5);
    
    return 0;
}
