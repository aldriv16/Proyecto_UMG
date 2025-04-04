#include <iostream>
using namespace std;

// Función que realiza operaciones matemáticas
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

int main() {
    double num1, num2;
    char operacion;

    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el signo (+ - * /): ";
    cin >> operacion;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    calcular(num1, num2, operacion); // Llamada a la función

    return 0;
}

