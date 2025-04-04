#include <iostream>
using namespace std;

int main() {
    int num1, num2, resultado;
    int *ptr1 = &num1;
    int *ptr2 = &num2;
    int *ptrResultado = &resultado;

    cout << "INGRESE PRIMER NUMERO A MULTIPLICAR: ";
    cin >> *ptr1;
    cout << "INGRESE SEGUNDO NUMERO A MULTIPLICAR: ";
    cin >> *ptr2;

    *ptrResultado = (*ptr1) * (*ptr2);

    cout << "______________________________" << endl;
    cout << "     " << *ptr1 << endl;
    cout << "   x " << *ptr2 << endl;
    cout << "------------------------------" << endl;
    cout << "     " << *ptrResultado << endl;

    return 0;
}
