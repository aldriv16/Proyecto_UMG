#include <iostream>
using namespace std;
 
int main() {
    int opcion;
 
    cout<<"Simulador de Tiempo"<<endl;
    cout<<"1. Convertir horas a minutos y segundos"<<endl;
    cout<<"2. Convertir minutos a horas y segundos"<<endl;
    cout<<"3. Convertir segundos a horas y minutos"<<endl;
    cout<<"Seleccione una opcion: ";
    cin >> opcion;
 
    switch (opcion) {
        case 1: {
            int horas;
            cout << "Ingrese las horas: ";
            cin >> horas;
            int minutos = horas * 60;
            int segundos = horas * 3600;
            cout << "Equivalente en minutos: " << minutos << " minutos" << endl;
            cout << "Equivalente en segundos: " << segundos << " segundos" << endl;
            break;
        }
        case 2: {
            int minutos;
            cout << "Ingrese los minutos: ";
            cin >> minutos;
            double horas = minutos / 60.0;
            int segundos = minutos * 60;
            cout << "Equivalente en horas: " << horas << " horas" << endl;
            cout << "Equivalente en segundos: " << segundos << " segundos" << endl;
            break;
        }
        case 3: {
            int segundos;
            cout << "Ingrese los segundos: ";
            cin >> segundos;
            double horas = segundos / 3600.0;
            double minutos = (segundos % 3600) / 60.0;
            cout << "Equivalente en horas: " << horas << " horas" << endl;
            cout << "Equivalente en minutos: " << minutos << " minutos" << endl;
            break;
        }
        default:
            cout << "Opcion no valida." << endl;
        return 0;
    }
}
