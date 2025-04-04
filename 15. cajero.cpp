#include <iostream>
using namespace std;

int main(){
	int saldo_inicial =1000;
	int saldo, reintegro,opcion,agregar;
	
	cout << "\tBienvenido a su cajero virtual";
    cout << "\nEscoger una opcion";
    cout << "\n1. ingreso en cuenta";
    cout << "\n2. reintegro";
    cout << "\n3. ver saldo de cuenta";
    cout << "\n0. salir";
    cout << "\nOpcion: ";
	cin >> opcion;

		if(opcion==1){
			cout << "\nIngresar la cantidad a depositar:";
			cin >> agregar;
			saldo= saldo_inicial + agregar;
			
			cout << "\nCantidad disponible en cuenta: "<<saldo;
			cin >> agregar;
		}	
		else if(opcion==2){
			cout << "\ncuanta cantidad desea retirar: ";
			cin >> reintegro;
			if(reintegro>3000){
				cout << "la cantidad digital es mayor a 3,000 Q, Digite de nuevo la cantidad  ";
				cin >> reintegro;
		}		
		
		saldo= saldo_inicial- reintegro;
			cout << "\nCantidad disponible en cuenta: "<<saldo;
			}
		else if(opcion == 3){
			cout << "\nCantidad disponible en cuenta es de: "<<saldo_inicial;
			}

			else if(opcion==0){
			cout << "gracias por utilizar nuestro cajero automatico";
			}
			else{
				cout << "opcion invalida";
			}	
			
			cin.get();
			return 0;
}

