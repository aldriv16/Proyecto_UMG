#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

// Función que implementa el método de Horner, muestra los pasos y valida el resultado
double metodoHorner(const vector<double>& coef, double x) {
    double resultado = coef[0];
    
    cout << "\n+------+--------------+----------------------|" << endl;
    cout << "| Paso | Coeficiente | Resultado Parcial   |" << endl;
    cout << "+------+--------------+----------------------|" << endl;
    cout << "|  0   | " << setw(10) << coef[0] << "  | " << setw(18) << coef[0] << "  |" << endl;
    
    for (size_t i = 1; i < coef.size(); i++) {
        resultado = resultado * x + coef[i];
        cout << "| " << setw(3) << i << "   | " << setw(10) << coef[i] << "  | " << setw(18) << resultado << "  |" << endl;
    }
    cout << "+------+--------------+----------------------|" << endl;
    return resultado;
}

// Función para validar el resultado calculando el polinomio directamente
double validarResultado(const vector<double>& coef, double x) {
    double resultado = 0;
    int grado = coef.size() - 1;
    
    for (int i = 0; i <= grado; i++) {
        resultado += coef[i] * pow(x, grado - i);
    }
    return resultado;
}

int main() {
    int grado;
    cout << "Ingrese el grado del polinomio: ";
    cin >> grado;
    
    vector<double> coeficientes(grado + 1);
    cout << "Ingrese los coeficientes del polinomio (de mayor a menor grado):\n";
    
    for (int i = 0; i <= grado; i++) {
        cout << "Coeficiente de x^" << (grado - i) << ": ";
        cin >> coeficientes[i];
        
        // Validación del coeficiente
        if (coeficientes[i] <= 0) {
            cerr << "?? Error: El coeficiente no puede ser menor o igual a 0. Programa terminado." << endl;
            exit(1);
        }
    }
    
    double x;
    cout << "Ingrese el valor de x: ";
    cin >> x;
    
    double resultadoHorner = metodoHorner(coeficientes, x);
    double resultadoValidacion = validarResultado(coeficientes, x);
    
    cout << "\nEl resultado del polinomio evaluado en x = " << x << " es: " << resultadoHorner << endl;
    cout << "Resultado validado con cálculo directo: " << resultadoValidacion << endl;
    
    if (abs(resultadoHorner - resultadoValidacion) < 1e-6) {
        cout << "\n? La validación fue exitosa, los resultados coinciden!" << endl;
    } else {
        cout << "\n? Advertencia: Hay una diferencia en los resultados, revise los cálculos." << endl;
    }
    
    return 0;
}

