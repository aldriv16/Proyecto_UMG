#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> unidades = {"", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
vector<string> decenas_especiales = {"diez", "once", "doce", "trece", "catorce", "quince", "dieciseis", "diecisiete", "dieciocho", "diecinueve"};
vector<string> decenas = {"", "diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
vector<string> centenas = {"", "cien", "doscientos", "trescientos", "cuatrocientos", "quinientos", 
                          "seiscientos", "setecientos", "ochocientos", "novecientos"};

string convertirGrupo(int numero) {
    if (numero == 0) return "";
    
    int c = numero / 100;
    int d = (numero % 100) / 10;
    int u = numero % 10;
    string resultado;
    
    if (c > 0) {
        resultado += centenas[c];
        if (d > 0 || u > 0) resultado += " ";
    }
    
    if (d == 1) {
        resultado += decenas_especiales[u];
    } else {
        if (d > 1) {
            resultado += decenas[d];
            if (u > 0) resultado += " y ";
        }
        if (u > 0 && d != 1) {
            resultado += unidades[u];
        }
    }
    
    return resultado;
}

string numeroALetras(int numero) {
    if (numero == 0) return "cero";
    
    string resultado;
    int miles = numero / 1000;
    int resto = numero % 1000;
    
    if (miles > 0) {
        resultado += convertirGrupo(miles) + " mil ";
    }
    
    resultado += convertirGrupo(resto);
    
    // Eliminar espacios extras
    size_t inicio = resultado.find_first_not_of(" ");
    size_t fin = resultado.find_last_not_of(" ");
    
    return inicio != string::npos ? resultado.substr(inicio, fin - inicio + 1) : "";
}

int main() {
    int numero;
    char opcion;
    
    do {
        cout << "Ingrese el numero deseado: ";
        cin >> numero;
        
        if (numero < 0 || numero > 999999) {
            cout << "Numero fuera de rango." << endl;
        } else {
            cout << "En letras: " << numeroALetras(numero) << endl;
        }
        
        cout << "Desea convertir otro numero? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');
    
    return 0;
}
