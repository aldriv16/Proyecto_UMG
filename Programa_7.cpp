#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib> // Para atoi

using namespace std;

// Declaración de vectores
vector<string> unidades;
vector<string> decenas_especiales;
vector<string> decenas;
vector<string> centenas;

// Función para inicializar los vectores
void inicializarVectores() {
    // Inicialización de unidades
    unidades.push_back("");
    unidades.push_back("uno");
    unidades.push_back("dos");
    unidades.push_back("tres");
    unidades.push_back("cuatro");
    unidades.push_back("cinco");
    unidades.push_back("seis");
    unidades.push_back("siete");
    unidades.push_back("ocho");
    unidades.push_back("nueve");

    // Inicialización de decenas especiales
    decenas_especiales.push_back("diez");
    decenas_especiales.push_back("once");
    decenas_especiales.push_back("doce");
    decenas_especiales.push_back("trece");
    decenas_especiales.push_back("catorce");
    decenas_especiales.push_back("quince");
    decenas_especiales.push_back("dieciseis");
    decenas_especiales.push_back("diecisiete");
    decenas_especiales.push_back("dieciocho");
    decenas_especiales.push_back("diecinueve");

    // Inicialización de decenas
    decenas.push_back("");
    decenas.push_back("diez");
    decenas.push_back("veinte");
    decenas.push_back("treinta");
    decenas.push_back("cuarenta");
    decenas.push_back("cincuenta");
    decenas.push_back("sesenta");
    decenas.push_back("setenta");
    decenas.push_back("ochenta");
    decenas.push_back("noventa");

    // Inicialización de centenas
    centenas.push_back("");
    centenas.push_back("cien");
    centenas.push_back("doscientos");
    centenas.push_back("trescientos");
    centenas.push_back("cuatrocientos");
    centenas.push_back("quinientos");
    centenas.push_back("seiscientos");
    centenas.push_back("setecientos");
    centenas.push_back("ochocientos");
    centenas.push_back("novecientos");
}

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

// Función alternativa a stoi para C++98
int stringAEntero(const string& str) {
    return atoi(str.c_str());
}

string numeroALetras(double numero) {
    stringstream ss;
    ss.precision(2);
    ss << fixed << numero;
    string num_str = ss.str();
    
    size_t punto = num_str.find('.');
    string parte_entera_str = num_str.substr(0, punto);
    string parte_decimal_str = num_str.substr(punto + 1, 2); // Tomamos solo 2 decimales
    
    int parte_entera = stringAEntero(parte_entera_str);
    int parte_decimal = stringAEntero(parte_decimal_str);
    
    string resultado = convertirParteEntera(parte_entera);
    
    if (parte_decimal > 0) {
        resultado += " punto " + convertirParteDecimal(parte_decimal);
    }
    
    return resultado;
}

int main() {
    // Inicializar los vectores
    inicializarVectores();
    
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
