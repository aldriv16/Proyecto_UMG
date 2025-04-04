#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <limits>
#include <cctype>

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
    char opcion;
    
    do {
        int grado;
        cout << "\nIngrese el grado del polinomio: ";
        while (!(cin >> grado) || grado < 0) {
            cout << "Error: Ingrese un número entero no negativo.\n";
            cout << "Ingrese el grado del polinomio: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        vector<double> coeficientes(grado + 1);
        cout << "Ingrese los coeficientes del polinomio (de mayor a menor grado):\n";
        
        for (int i = 0; i <= grado; i++) {
            cout << "Coeficiente de x^" << (grado - i) << ": ";
            while (!(cin >> coeficientes[i])) {
                cout << "Error: Ingrese un número válido.\n";
                cout << "Coeficiente de x^" << (grado - i) << ": ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            // Se eliminó la validación que impedía coeficientes = 0
        }
        
        double x;
        cout << "Ingrese el valor de x: ";
        while (!(cin >> x)) {
            cout << "Error: Ingrese un número válido.\n";
            cout << "Ingrese el valor de x: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        double resultadoHorner = metodoHorner(coeficientes, x);
        double resultadoValidacion = validarResultado(coeficientes, x);
        
        cout << "\nEl resultado del polinomio evaluado en x = " << x << " es: " << resultadoHorner << endl;
        cout << "Resultado validado con cálculo directo: " << resultadoValidacion << endl;
        
        if (abs(resultadoHorner - resultadoValidacion) < 1e-6) {
            cout << "\n? La validación fue exitosa, los resultados coinciden!" << endl;
        } else {
            cout << "\n? Advertencia: Hay una diferencia en los resultados, revise los cálculos." << endl;
        }
        
        cout << "\n¿Desea evaluar otro polinomio? (s/n): ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
    } while (tolower(opcion) == 's');
    
    cout << "\nPresione Enter para salir...";
    cin.ignore();
    
    return 0;
}
