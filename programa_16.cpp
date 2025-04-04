#include <iostream>
using namespace std;
float raizCuadrada(float numero) {
    float bajo = 0, alto = numero, medio;
    while (alto - bajo > 0.0001) {
        medio = (bajo + alto) / 2;
        if (medio * medio > numero) {
            alto = medio;
        } else {
            bajo = medio;
        }
    }
    return medio;
}
int main() {
    float cateto1, cateto2, hipotenusa;
    cout << "Ingrese el primer cateto: ";
    cin >> cateto1;
    cout << "Ingrese el segundo cateto: ";
    cin >> cateto2;
    hipotenusa = cateto1 * cateto1 + cateto2 * cateto2;
    hipotenusa = raizCuadrada(hipotenusa);
    cout << "La hipotenusa es: " << hipotenusa << endl;
    return 0;
}

