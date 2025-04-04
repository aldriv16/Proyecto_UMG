#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void mostrarMenu() {
    system("cls");
    cout << "=============================================" << endl;
    cout << "          MENU DE PROGRAMAS EN Dev-C++       " << endl;
    cout << "=============================================" << endl;
    cout << "1. Verificador de Palindromos" << endl;
    cout << "2. Conversor de Numeros Enteros a Letras" << endl;
    cout << "3. Conversor de Numeros Decimales a Letras" << endl;
    cout << "4. Metodo de Horner para Polinomios" << endl;
    cout << "5. Salir" << endl;
    cout << "=============================================" << endl;
    cout << "Seleccione una opcion (1-5): ";
}

void ejecutarPrograma(const string& nombreArchivo) {
    // Comando específico para tu configuración TDM-GCC
    string comando = "g++ " + nombreArchivo + " -o " + nombreArchivo.substr(0, nombreArchivo.find('.')) + ".exe && start " + nombreArchivo.substr(0, nombreArchivo.find('.')) + ".exe";
    system(comando.c_str());
}

int main() {
    int opcion;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                ejecutarPrograma("Programa_4.cpp");
                break;
            case 2:
                ejecutarPrograma("Programa_6.cpp");
                break;
            case 3:
                ejecutarPrograma("Programa_7.cpp");
                break;
            case 4:
                ejecutarPrograma("Programa_20_libre.cpp");
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
        
        if (opcion != 5) {
            cout << "\nPresione Enter para volver al menu...";
            cin.ignore();
            cin.get();
        }
        
    } while (opcion != 5);
    
    return 0;
}
