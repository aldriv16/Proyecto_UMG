#include <iostream>
using namespace std;

// Función para verificar si un número es par o impar
void verificar(int numero) {
    if (numero % 2 == 0)
        cout << "El numero " << numero << " es par." << endl;
    else
        cout << "El numero " << numero << " es impar." << endl;
}

int main() {
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;
        verificar(numero);
    
    return 0;
}

