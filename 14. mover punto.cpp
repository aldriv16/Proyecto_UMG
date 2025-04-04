#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <windows.h> 

using namespace std;

int main() {
    // Tamaño del cuadro
    const int width = 20;
    const int height = 10;

    srand(time(0));

    // Coordenadas del asterisco
    int x = width / 2;
    int y = height / 2;

    // Bucle para el movimiento
    while (true) {
        // Limpiar la pantalla
        system("cls");

        // Dibujar el cuadro y el asterisco
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                // Dibujar los bordes del cuadro
                if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                    cout << "#";
                } 
                // Dibujar el asterisco en las coordenadas (x, y)
                else if (i == y && j == x) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        }

        // Mover el asterisco en una dirección aleatoria
        int direction = rand() % 4; // Genera un número aleatorio entre 0 y 3
        switch (direction) {
            case 0: // Arriba
                if (y > 1) y--;
                break;
            case 1: // Abajo
                if (y < height - 2) y++;
                break;
            case 2: // Izquierda
                if (x > 1) x--;
                break;
            case 3: // Derecha
                if (x < width - 2) x++;
                break;
        }


        Sleep(200);  // 200 milisegundos de pausa
    }

    return 0;
}

