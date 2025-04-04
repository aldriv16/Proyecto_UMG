#include <iostream>
using namespace std;
int main() {
    int numeroSecreto = 7; 
    int intento;
    int intentosRestantes = 3;
    cout << "__________ADIVINA EL NUMERO__________" << endl;
    cout << "Elige un numero del 1 al 10 : (tienes 3 intentos)" << endl;
    while (intentosRestantes > 0) {
        cout << "Tienes " << intentosRestantes << " intentos restantes." << endl;
        cout << "Ingresa tu intento: ";
        cin >> intento;
        if (intento == numeroSecreto) {
            cout << "¡Felicidades, has Ganado! " << endl;
            break; 
        } else {
            intentosRestantes--;
            if (intentosRestantes > 0) {
                if (intento > numeroSecreto) {
                    cout << "Muy Alto Intenta nuevamente." << endl;
                } else { cout << "Muy bajo Intenta nuevamente." << endl; }
            } else { cout << "GAME OVER!. El numero secreto era " << numeroSecreto << "." << endl;
            }
        }
    }
    return 0;
}
