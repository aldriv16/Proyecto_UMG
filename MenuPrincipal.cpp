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
    cout << "5. Calculadora" << endl;
    cout << "6. Numeros pares eh impares" << endl;    
    cout << "7. Conversiones de unidades de medida" << endl;
    cout << "8. Conversion de tiempo (programa libre)" << endl;
    cout << "9. Salir" << endl;
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
                system("g++ -o calcular 1.Operaciones.cpp  && 1.Operaciones.exe");
                break;
            case 6:
                system("g++ -o verificar  2.pares.cpp  && 2.pares.exe");
                break;
            case 7:
                system("g++ -o convertirUnidades  3.conversiones.cpp  && 3.conversiones.exe");
                break;
            case 8:
                system("g++ -o opcion  libre.cpp  && libre.exe");
                break;    
			case 9:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
        }
        
    } while (opcion != 5);
    
    return 0;
}
