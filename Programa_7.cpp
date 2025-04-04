#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

vector<string> unidades = {"", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
vector<string> decenas_especiales = {"diez", "once", "doce", "trece", "catorce", "quince", 
                                    "dieciseis", "diecisiete", "dieciocho", "diecinueve"};
vector<string> decenas = {"", "diez", "veinte", "treinta", "cuarenta", "cincuenta", 
                         "sesenta", "setenta", "ochenta", "noventa"};
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

string convertirParteEntera(int numero) {
    if (numero == 0) return "cero";
    
    string resultado;
    int millones = numero / 1000000;
    int resto_millones = numero % 1000000;
    int miles = resto_millones / 1000;
    int resto = resto_millones % 1000;
    
    if (millones > 0) {
        resultado += convertirGrupo(millones) + " millon" + (millones > 1 ? "es " : " ");
    }
    
    if (miles > 0) {
        resultado += convertirGrupo(miles) + " mil ";
    }
    
    resultado += convertirGrupo(resto);
    
    // Eliminar espacios extras
    size_t inicio = resultado.find_first_not_of(" ");
    size_t fin = resultado.find_last_not_of(" ");
    
    return inicio != string::npos ? resultado.substr(inicio, fin - inicio + 1) : "";
}

string convertirParteDecimal(int decimal) {
    if (decimal == 0) return "cero";
    return convertirGrupo(decimal);
}

string numeroALetras(double numero) {
    stringstream ss;
    ss.precision(2);
    ss << fixed << numero;
    string num_str = ss.str();
    
    size_t punto = num_str.find('.');
    string parte_entera_str = num_str.substr(0, punto);
    string parte_decimal_str = num_str.substr(punto + 1, 2); // Tomamos solo 2 decimales
    
    int parte_entera = stoi(parte_entera_str);
    int parte_decimal = stoi(parte_decimal_str);
    
    string resultado = convertirParteEntera(parte_entera);
    
    if (parte_decimal > 0) {
        resultado += " punto " + convertirParteDecimal(parte_decimal);
    }
    
    return resultado;
}

int main() {
    double numero;
    char opcion;
    
    cout << "CONVERSOR DE NUMEROS A LETRAS (con decimales)" << endl;
    
    do {
        cout << "\nIngrese un numero: ";
        cin >> numero;
        
        cout << "\nEn letras: " << numeroALetras(numero) << endl;
        
        cout << "\nDesea convertir otro numero? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');
    
    return 0;
}
