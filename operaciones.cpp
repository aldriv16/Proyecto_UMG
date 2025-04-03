#include <iostream>
using namespace std;

// Verificar par o impar
void verificarParidad(int numero) {
    if (numero % 2 == 0)
        cout << "El numero " << numero << " es par." << endl;
    else
        cout << "El numero " << numero << " es impar." << endl;
}

// Operaciones matemáticas
void calcular(double num1, double num2, char operacion) {
    switch (operacion) {
        case '+':
            cout << "Resultado: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Resultado: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Resultado: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << "Resultado: " << num1 / num2 << endl;
            else
                cout << "Error: Division por cero no permitida." << endl;
            break;
        default:
            cout << "Operacion no valida." << endl;
    }
}

// Conversor de unidades
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

// cronometro
void crono(int opcion, int valor) {
    switch (opcion) {
        case 1:
            cout << "Resultado: " << valor * 60 << " minutos" << endl;
            break;
        case 2:
            cout << "Resultado: " << valor * 3600 << " segundos" << endl;
            break;
        case 3:
            cout << "Resultado: " << valor / 60.0 << " horas" << endl;
            break;
        case 4:
            cout << "Resultado: " << valor * 60 << " segundos" << endl;
            break;
        case 5:
            cout << "Resultado: " << valor / 3600.0 << " horas" << endl;
            break;
        case 6:
            cout << "Resultado: " << valor / 60.0 << " minutos" << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
    }
}


// Menu principal
int main() {
    int opcion;
    do {
        system("cls");
        
        cout << "\n  ***Menu Principal***" << endl;
        cout << " Seleccione una opcion:" << endl;
        cout << "\n1. Calculadora" << endl;
        cout << "2. Verificar Par o Impar" << endl;
        cout << "3. Conversor de Unidades" << endl;
        cout << "4. Conversor de Tiempo" << endl;
        cout << "5. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1: {
                double num1, num2;
                char operacion;
                cout << "Ingrese el primer numero: ";
                cin >> num1;
                cout << "Ingrese el signo (+ - * /): ";
                cin >> operacion;
                cout << "Ingrese el segundo numero: ";
                cin >> num2;
                calcular(num1, num2, operacion);
                break;
            }
            case 2: {
                int numero;
                cout << "Ingrese un numero: ";
                cin >> numero;
                verificarParidad(numero);
                break;
            }
            case 3: {
                int subopcion;
                double valor;
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
                break;
            }
            case 4: {
                int subopcion, valor;
                cout << "\nConversor de Tiempo" << endl;
                cout << "1. Horas a Minutos" << endl;
                cout << "2. Horas a Segundos" << endl;
                cout << "3. Minutos a Horas" << endl;
                cout << "4. Minutos a Segundos" << endl;
                cout << "5. Segundos a Horas" << endl;
                cout << "6. Segundos a Minutos" << endl;
                cout << "Seleccione una opcion: ";
                cin >> subopcion;
                cout << "Ingrese el valor a convertir: ";
                cin >> valor;
                crono(subopcion, valor);
                break;
            }
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
        }
        cout << "\nPresione Enter para continuar...";
        cin.ignore();
        cin.get();
    } while (opcion != 5);

    return 0;
}

